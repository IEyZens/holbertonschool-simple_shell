#include "shell.h"

/**
 * main - Boucle principale du shell
 *
 * Return: 0 à la fin du programme
 */
int main(void)
{
	char *input;

	setbuf(stdout, NULL);

	while (1)
	{
		input = display_prompt();

		if (!input || input[0] == '\0')
		{
			free(input);
			continue;
		}

		execute_command(input);
		free(input);
	}

	return (0);
}

