#include "main.h"

/**
 * prompt - affiche le prompt
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 8);
}

/**
 * read_line - lit une ligne depuis stdin
 * Return: ligne allouée
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * free_args - libère le tableau d’arguments
 * @args: arguments à libérer
 */
void free_args(char **args)
{
	int i = 0;

	if (!args)
		return;

	while (args[i])
		free(args[i++]);
	free(args);
}
