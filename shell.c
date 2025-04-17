#include "shell.h"

/**
 * main - Fonction qui produit une sortie selon la commande en entrée
 *
 * Return: Toujours 0
 */
int main(void)
{
	char command[100];
	pid_t pid;
	char *argv[2];

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			exit(0);
		}
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
			continue;

		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			continue;
		}
		else if (pid == 0)
		{
			argv[0] = command;
			argv[1] = NULL;

			if (execve(command, argv, environ) == -1)
			{
				perror("execve failed");
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
