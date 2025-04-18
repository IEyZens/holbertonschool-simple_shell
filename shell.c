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
			free_and_null(&input);
			continue;
		}

		execute_command(input);
		free_and_null(&input);
	}

	return (0);
}
