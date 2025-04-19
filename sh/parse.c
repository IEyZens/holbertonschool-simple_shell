#include "main.h"

/**
 * parse_line - découpe la ligne en tokens
 * @line: ligne entrée par l'utilisateur
 * 
 * Return: tableau de tokens
 */
char **parse_line(char *line)
{
	char *token = NULL;
	char **args = malloc(sizeof(char *) * 64);
	int i = 0;

	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	while (token)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return (args);
}
