#include "shell.h"

/**
 * main - Fonction qui produit une sortie selon la commande en entrée
 *
 * Return: Toujours 0
 */
int main(void)
{
	pid_t pid;
	char *argv[2];
	char *input;

	while (1)
	{
		input = display_prompt();

		if (input[0] == 0)
		{
			free(input);
			continue;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			free(input);
			continue;
		}
		else if (pid == 0)
		{
			argv[0] = input;
			argv[1] = NULL;

			if (execve(input, argv, environ) == -1)
			{
				perror("execve failed");
				exit(1);
			}
		}
		else
		{
			wait(NULL);
			free(input);
		}
	}

	return (0);
}
