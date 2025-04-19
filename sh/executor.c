#include "shell.h"

/**
 * execute_cmd - exécute les commandes entrées par l'utilisateur
 * @cmd: est un char pointeur
 */
void execute_cmd(char *cmd)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *argv[] = {cmd, NULL};

		if (execve(cmd, argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}
