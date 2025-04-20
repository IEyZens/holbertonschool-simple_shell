#include "shell.h"

/**
 * main - Boucle principale du shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;
	int i;

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
		else if (_strcmp(command, "env") == 0)
		{
			for (i = 0; environ[i]; i++)
			{
				write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
			free(command);
			continue;
		}

		execute_command(command);
		free(command);
	}

	return (0);
}
