#include "main.h"

/**
 * main - point d’entrée du shell
 * 
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	char **args = NULL;

	while (1)
	{
		prompt();
		line = read_line();
		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		args = parse_line(line);
		if (args == NULL || args[0] == NULL)
		{
			free(line);
			free_args(args);
			continue;
		}

		if (is_builtin(args[0]))
			exec_builtin(args);
		else
			execute(args);

		free(line);
		free_args(args);
	}

	return (0);
}
