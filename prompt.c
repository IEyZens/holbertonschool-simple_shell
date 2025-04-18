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
	int read;
	
	read = getline(&command, &len, stdin);

	if (read == -1)
	{
		free(command);
		return (NULL);
	}

	if (command[read - 1] == '\n')
		command[read - 1] = '\0';

	return (command);
}
