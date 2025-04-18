#include "shell.h"

/**
 * execute_command - Exécute une commande entrée
 * @input: commande à exécuter
 */
void execute_command(char *input)
{
	pid_t pid;
	char *argv[2];

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		argv[0] = input;
		argv[1] = NULL;

		if (execve(input, argv, environ) == -1)
		{
			perror("./shell");
			_exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
