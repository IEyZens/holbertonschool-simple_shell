#include "shell.h"

/**
 * prompt - affiche le prompt si terminal interactif
 */
void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
