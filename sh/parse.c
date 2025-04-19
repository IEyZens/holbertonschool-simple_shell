#include "shell.h"

/**
 * read_line - lit une ligne depuis stdin
 *
 * Return: ligne allouée (à free), ou NULL si Ctrl+D
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
