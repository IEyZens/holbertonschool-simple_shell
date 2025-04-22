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

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
	}
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
	char *path = malloc(len1 + len2 + 2);

	if (!path)
		return (NULL);

	strcpy(path, dir);
	path[len1] = '/';
	strcpy(path + len1 + 1, command);
	path[len1 + 1 + len2] = '\0';

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

	path = get_path_env();
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = build_full_path(dir, command);
		if (!full_path)
			break;

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

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
	if (access(command, X_OK) == 0)
		return (command);
	return (find_command_path(command));
}
