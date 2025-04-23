#include "shell.h"

/**
 * parse_args - Permet d'exécuter des commandes avec arguments (ex : ls -l)
 * @command: est un char pointeur
 *
 * Return: Always char
 */
char **parse_args(char *command)
{
	/* argv : tableau dynamique des arguments | temp : utilisé pour realloc */
	char **argv = NULL, **temp;
	/* Pointeur pour stocker chaque "mot" de la commande */
	char *token;
	/* i : index du tableau | size : capacité actuelle de argv */
	int i = 0, size = 8;

	/* Allocation initiale pour 8 arguments */
	argv = malloc(sizeof(char *) * size);
	if (argv == NULL)
		/* Échec d'allocation */
		return (NULL);

	/* Séparation de la commande par les espaces (1er token) */
	token = strtok(command, " ");
	/* Tant qu'on trouve des tokens */
	while (token)
	{
		/* Ajout du token dans le tableau argv */
		argv[i++] = token;

		/* Si on dépasse la taille actuelle du tableau */
		if (i >= size)
		{
			/* On double la taille */
			size = size * 2;
			/* Réallocation avec la nouvelle taille */
			temp = realloc(argv, sizeof(char *) * size);
			/* En cas d'échec */
			if (temp == NULL)
			{
				/* Libère le tableau */
				free(argv);
				/* On retourne NULL */
				return (NULL);
			}

			/* On met à jour le pointeur argv avec le nouvel espace mémoire */
			argv = temp;
		}

		/* On passe au token suivant */
		token = strtok(NULL, " ");
	}

	/* Le tableau se termine par NULL (convention execvp) */
	argv[i] = NULL;
	/* On retourne le tableau d'arguments */
	return (argv);
}

/**
 * execute_command - Lancement des commandes
 * @command: est un char pointeur
 */
void execute_command(char *command)
{
	/* Identifiant de processus pour fork */
	pid_t pid;
	/* Pour récupérer le code de retour du processus enfant */
	int status;
	/* argv : tableau d'arguments | path : chemin absolu de la commande */
	char **argv, *path;

	/* Si la commande est vide ou NULL */
	if (!command || *command == '\0')
		return;

	/* On découpe la commande en arguments */
	argv = parse_args(command);
	/* Si la commande est vide après parsing */
	if (!argv || !argv[0])
	{
		/* On libère le tableau */
		free(argv);
		/* On retourne rien */
		return;
	}

	/* Recherche du chemin absolu de la commande */
	path = resolve_path(argv[0]);
	/* Si la commande n'est pas trouvée */
	if (!path)
	{
		/* Affiche un message d'erreur */
		print_error(argv[0]);
		/* On libère le tableau */
		free(argv);
		/* On retourne rien */
		return;
	}

	/* Création d’un processus fils */
	pid = fork();
	/* Erreur lors du fork */
	if (pid == -1)
	{
		/* Message d'erreur standard */
		write(STDERR_FILENO, "Error: fork failed\n", 19);
		/* Nettoyage */
		clean_and_return(path, argv, argv[0]);
		/* On retourne rien */
		return;
	}

	/* Code exécuté par le processus fils */
	if (pid == 0)
		/* Fonction qui exécute la commande */
		run_child_process(path, argv);

	/* Le parent attend que le processus enfant se termine */
	waitpid(pid, &status, 0);
	/* Libération de la mémoire utilisée */
	clean_and_return(path, argv, argv[0]);
}

