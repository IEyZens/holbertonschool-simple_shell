#include "shell.h"

/**
 * execute_command - Il exécute toutes les commandes pour le shell.c
 * @input: est un char pointeur
 */
void execute_command(char *input)
{
	pid_t pid;
	char *argv[2];

	pid = fork();
	if (pid == -1)
	{
		write(2, "./shell: No such file or directory\n", 36);
		return;
	}

	if (pid == 0)
	{
		if (access(input, X_OK) != 0)
		{
			print_error();
			exit(1);
		}

		argv[0] = input;
		argv[1] = NULL;
		execve(input, argv, environ);

		write(2, "./shell: No such file or directory\n", 36);
		return;
	}
	else
	{
		wait(NULL);
	}
}
