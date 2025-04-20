#include "shell.h"

/**
 * handle_builtin - Permet d'exécuter les commandes exit et env
 * @command: est un char pointeur
 *
 * Return: Always 0
 */
int handle_builtin(char *command)
{
	if (_strcmp(command, "exit") == 0)
		return (1);

	if (_strcmp(command, "env") == 0)
	{
		print_env();
		return (0);
	}

	return (-1);
}

/**
 * print_env - Permet d'imprimer l'environnement actuel
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
