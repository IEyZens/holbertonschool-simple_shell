#include "shell.h"

/**
 *
 */
#include "shell.h"

int handle_builtin(char *command)
{
	if (_strcmp(command, "exit") == 0)
	{
		return (1);
	}
	else if (_strcmp(command, "env") == 0)
	{
		print_env();
		return (0);
	}
	return (-1);
}

void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
