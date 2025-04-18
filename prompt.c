#include "shell.h"

/**
 * display_prompt - Affiche un symbole pour l'entrée d'une commande
 *
 * Return: Always char
 */
char *display_prompt(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);

	read = getline(&command, &len, stdin);

	if (read == -1)
	{
		free(command);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}

	if (command[read - 1] == '\n')
		command[read - 1] = '\0';

	return (command);
}
