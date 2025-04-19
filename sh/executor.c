#include "shell.h"

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
