#include "shell.h"

/**
 * main - Boucle principale du shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;
	int b_status;

	while (1)
	{
		command = read_command();

		if (command == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		b_status = handle_builtin(command);

		if (b_status == 1)
		{
			free(command);
			break;
		}
		else if (b_status == 0)
		{
			free(command);
			continue;
		}

		execute_command(command);
		free(command);
	}

	return (0);
}
