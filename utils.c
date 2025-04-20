#include "shell.h"

/**
 * print_error - Imprime les erreurs
 */
void print_error(void)
{
	write(STDERR_FILENO, "./shell: No such file or directory\n", 35);
}
