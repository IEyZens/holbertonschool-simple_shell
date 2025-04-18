#include "shell.h"

/**
 * main - Fonction qui produit une sortie selon la commande en entrée
 *
 * Return: Toujours 0
 */
int main(void)
{
	char *input;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		input = display_prompt();

		if (input == NULL)
			break;

		status = execute_command(input);
		if (status == 2)
			exit(2);
	}

	return (status);
}
