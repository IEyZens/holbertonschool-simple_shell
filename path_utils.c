#include "shell.h"

/**
 * get_path_env - Permet de récupérer la valeur de la variable
 * d'environnement PATH
 *
 * Return: Always char
 */
char *get_path_env(void)
{
	int i;

	/* Parcours du tableau global des variables d’environnement */
	for (i = 0; environ[i]; i++)
	{
		/* Si on trouve "PATH=" au début d'une variable */
		if (strncmp(environ[i], "PATH=", 5) == 0)
			/* On retourne un pointeur vers le contenu après "PATH=" */
			return (environ[i] + 5);
	}
	/* Si la variable PATH n’est pas trouvée */
	return (NULL);
}

/**
 * build_full_path - Permet d'assembler le chemin complet vers une commande
 * @dir: est un char pointeur
 * @command: est un char pointeur
 *
 * Return: Always char
 */
char *build_full_path(char *dir, char *command)
{
	int len1 = strlen(dir);
	int len2 = strlen(command);
	/* +1 pour '/' et +1 pour '\0' */
	char *path = malloc(len1 + len2 + 2);

	if (!path)
		/* Allocation échouée */
		return (NULL);

	/* Copie du répertoire */
	strcpy(path, dir);
	/* Ajout du séparateur */
	path[len1] = '/';
	/* Ajout de la commande après le '/' */
	strcpy(path + len1 + 1, command);
	/* Terminaison de la chaîne */
	path[len1 + 1 + len2] = '\0';

	/* Retourne le chemin complet */
	return (path);
}

/**
 * find_command_path - Permet de chercher une commande dans tous les dossiers
 * indiqués par la variable d'environnement PATH
 * @command: est un char pointeur
 *
 * Return: Always char
 */
char *find_command_path(char *command)
{
	char *path, *dir, *path_copy, *full_path;

	/* Récupération du contenu de PATH */
	path = get_path_env();
	if (!path)
		return (NULL);

	/* On fait une copie car strtok modifie la chaîne originale */
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	/* Découpage de la chaîne PATH en répertoires */
	dir = strtok(path_copy, ":");
	while (dir)
	{
		/* Création du chemin complet */
		full_path = build_full_path(dir, command);
		if (!full_path)
			break;

		/* Vérifie si le fichier est exécutable */
		if (access(full_path, X_OK) == 0)
		{
			/* Libère la copie de PATH */
			free(path_copy);
			/* Retourne le chemin valide */
			return (full_path);
		}

		/* Le chemin n'est pas correct, on libère */
		free(full_path);
		/* On passe au répertoire suivant */
		dir = strtok(NULL, ":");
	}

	/* Aucun chemin valide trouvé */
	free(path_copy);
	return (NULL);
}

/**
 * resolve_path - Permet de trouver le chemin absolu vers une commande
 * que l'utilisateur a tapée
 * @command: est un char pointeur
 *
 * Return: Always char
 */
char *resolve_path(char *command)
{
	/* Si la commande est déjà un chemin valide */
	if (access(command, X_OK) == 0)
		/* On la retourne telle quelle */
		return (command);

	/* Sinon, on cherche dans le PATH */
	return (find_command_path(command));
}
