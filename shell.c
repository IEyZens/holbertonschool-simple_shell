#include "shell.h"

/**
 * main - Boucle principale du shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;

	while (1)
	{
		command = read_command();

		if (command == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}

		execute_command(command);
		free(command);
	}

	return (0);
}
