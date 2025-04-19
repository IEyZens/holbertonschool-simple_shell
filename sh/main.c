#include "main.h"

/**
 * main - boucle principale du shell
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL;

	while (1)
	{
		prompt();
		line = read_line();
		if (line == NULL)
			break;

		trim_newline(line);

		if (is_empty(line))
		{
			free(line);
			continue;
		}

		execute(line);
		free(line);
	}

	return (0);
}
