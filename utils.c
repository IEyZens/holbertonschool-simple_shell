#include "shell.h"

/**
 * print_error - Il permet de print les erreurs pour les fichiers .c
 */
void print_error(void)
{
	write(2, "./shell: No such file or directory\n", 36);
}

/**
 * free_and_null - Il permet de free dans les fichiers .c
 * @ptr: est un char double pointeur
 */
void free_and_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * _strlen - Compte le nombre de caractères
 * @str: est un char pointeur
 *
 * Return: Always 0
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
