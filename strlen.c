#include "shell.h"

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
