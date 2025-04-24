#include "shell.h"

/**
 * print_error - Imprime les erreurs
 * @command: est un char pointeur
 */
void print_error(char *command)
{
	/* Affiche le nom du shell */
	write(STDERR_FILENO, "./shell: ", 9);
	/* Affiche le nom de la commande */
	write(STDERR_FILENO, command, strlen(command));
	/* Message d'erreur standard */
	write(STDERR_FILENO, ": No such file or directory\n", 29);
}

/**
 * run_child_process - Exécuter la commande dans le processus enfant
 * @path: est un char pointeur
 * @argv: est un char double pointeur
 */
void run_child_process(char *path, char **argv)
{
	/* Remplace le processus courant par la commande à exécuter */
	execve(path, argv, environ);
	/* Si execve échoue, cette ligne s'exécute */
	print_error(argv[0]);
	/* Quitte le processus enfant avec un code d’erreur */
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
	/* Si path a été alloué dynamiquement (et est différent de la commande elle-même) */
	if (path != original)
		/* On le libère */
		free(path);
	/* On libère également le tableau d’arguments */
	free(argv);
}
