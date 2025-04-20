#include "shell.h"

/**
 * execute_command - Lancement des commandes
 * @command: est un char pointeur
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *argv[2];

	if (command == NULL || *command == '\0')
		return;

	if (access(command, X_OK) != 0)
	{
		print_error();
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return;
	}

	if (pid == 0)
	{
		argv[0] = command;
		argv[1] = NULL;

		execve(command, argv, environ);

		perror("execve failed");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
