#include "shell.h"

char *display_prompt(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");

	read = getline(&command, &len, stdin);

	if (read == -1)
	{
		if (isatty(STDIN_FILENO))
			printf("\n");
		free(command);
		exit(0);
	}

	if (command[read - 1] == '\n')
		command[read - 1] = '\0';

	return (command);
}
