#include "shell.h"

/**
 * read_command - Permet de lire les commandes entrées par l'utilisateur
 *
 * Return: Always char
 */
char *read_command(void)
{
	/* Pointeur initialisé à NULL pour que getline puisse allouer la mémoire automatiquement */
	char *line = NULL;
	/* Taille initiale du buffer, modifiée par getline si nécessaire */
	size_t len = 0;
	/* Nombre de caractères lus, ou -1 si erreur / EOF */
	ssize_t nread;

	/* Vérifie si l'entrée standard vient d’un terminal (mode interactif) */
	if (isatty(STDIN_FILENO))
		/* Affiche un prompt personnalisé */
		write(STDOUT_FILENO, "#cisfun$ ", 9);

	/* Lit une ligne complète de l'entrée standard */
	nread = getline(&line, &len, stdin);

	/* En cas d'erreur de lecture ou de fin de fichier (Ctrl+D) */
	if (nread == -1)
	{
		/* Libération du buffer */
		free(line);
		/* Retourne NULL pour signaler la fin de la lecture */
		return (NULL);
	}

	/* Si la ligne se termine par un saut de ligne */
	if (nread > 0 && line[nread - 1] == '\n')
		/* On remplace le '\n' par un caractère de fin de chaîne */
		line[nread - 1] = '\0';

	/* On retourne la ligne lue (commande entrée par l'utilisateur) */
	return (line);
}
