#include "shell.h"

/**
 * main - Boucle principale du shell
 *
 * Return: Always 0
 */
int main(void)
{
	/* Pointeur vers la chaîne qui contiendra la commande entrée par l'utilisateur */
	char *command;
	/* Variable utilisée pour itérer dans l'affichage des variables d'environnement */
	int i;

	/* Boucle infinie qui représente le coeur du shell */
	while (1)
	{
		/* Lecture de la commande entrée par l'utilisateur */
		command = read_command();

		/* Si la lecture échoue (ex : EOF reçu) */
		if (!command)
		{
			/* Si l'entrée standard est un terminal */
			if (isatty(STDIN_FILENO))
				/* Écrit un retour à la ligne pour le formatage */
				write(STDOUT_FILENO, "\n", 1);
			/* Sortie de la boucle principale */
			break;
		}

		/* Si l'utilisateur entre la commande "exit" */
		if (strcmp(command, "exit") == 0)
		{
			/* Libère la mémoire allouée à la commande */
			free(command);
			/* Sortie du shell */
			break;
		}

		/* Si l'utilisateur entre la commande "env" */
		if (strcmp(command, "env") == 0)
		{
			/* Parcours du tableau des variables d'environnement */
			for (i = 0; environ[i]; i++)
			{
				/* Affiche chaque variable */
				write(STDOUT_FILENO, environ[i], strlen(environ[i]));
				/* Retour à la ligne après chaque variable */
				write(STDOUT_FILENO, "\n", 1);
			}
			/* Libère la mémoire allouée à la commande "env" */
			free(command);
			/* Passe à l’itération suivante de la boucle */
			continue;
		}

		/* Si la commande n’est ni "exit" ni "env", elle est exécutée */
		execute_command(command);
		/* Libère la mémoire allouée à la commande après exécution */
		free(command);
	}

	/* Retourne 0 si succès */
	return (0);
}
