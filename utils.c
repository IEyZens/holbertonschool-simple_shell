#include "shell.h"

/**
 * print_error - Imprime les erreurs
 */
void print_error(void)
{
	write(STDERR_FILENO, "./shell: No such file or directory\n", 35);
}

/**
 * run_child_process - Exécuter la commande dans le processus enfant
 * @path: est un char pointeur
 * @argv: est un char double pointeur
 */
void run_child_process(char *path, char **argv)
{
	execve(path, argv, environ);
	print_error();
	exit(1);
}

/**
 * clean_and_return - Libère la mémoire allouée (argv et PATH)
 * à la fin de l'exécution ou en cas d'erreur
 * @path: est un char pointeur
 * @argv: est un char double pointeur
 * @original: est un char pointeur
 */
void clean_and_return(char *path, char **argv, char *original)
{
	if (path != original)
		free(path);
	free(argv);
}
