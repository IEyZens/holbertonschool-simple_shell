#include "shell.h"

/**
 * main - Fonction qui produit une sortie selon la commande en entrée
 *
 * Return: Toujours 0
 */
int main(void)
{
	char *input;

	setbuf(stdout, NULL);

	while (1)
	{
		input = display_prompt();

		if (!input || input[0] == '\0')
		{
			free_and_null(&input);
			continue;
		}

		execute_command(input);
		free_and_null(&input);
	}

	return (0);
}
