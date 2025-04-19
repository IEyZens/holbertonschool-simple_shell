#include "main.h"

/**
 * prompt - affiche le prompt si terminal interactif
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);
}
