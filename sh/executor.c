#include "main.h"

/**
 * execute - fork et execve sur la commande entrée
 * @line: commande tapée
 */
void execute(char *line)
{
	char *argv[2];

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		return;
	}

	if (pid == 0)
	{
		argv[0] = line;
		argv[1] = NULL;

		if (execve(line, argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
