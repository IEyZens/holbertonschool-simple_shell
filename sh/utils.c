#include "main.h"

/**
 * trim_newline - remplace le \n final par \0
 * @line: ligne à modifier
 *
 * Return: pointeur modifié
 */
char *trim_newline(char *line)
{
	size_t len = strlen(line);

	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

/**
 * is_empty - vérifie si une ligne est vide (ex: juste entrée)
 * @line: ligne à tester
 *
 * Return: 1 si vide, 0 sinon
 */
int is_empty(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t')
			return (0);
		line++;
	}
	return (1);
}
