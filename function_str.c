#include "shell.h"

/**
 * _strncmp - Permet de comparer n premiers caractères de deux chaînes
 * @s1: est un char pointeur constant
 * @s2: est un char pointeur constant
 * @n: est un int
 *
 * Return: Always 0
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strdup - Permet d'allouer une nouvelle chaîne et copier le contenu d'une
 * autre dedans
 * @str: est un char pointeur constant
 *
 * Return: Always char
 */
char *_strdup(const char *str)
{
	int i, len = 0;
	char *dup;

	while (str[len])
		len++;

	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}

/**
 * _strlen - Permet de retourner la longue d'une chaîne (sans compter \0)
 * @s: est un char pointeur constant
 *
 * Return: Always 0
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
 * _strcat - Permet de concatener deux chaînes de caractères
 * @dest: est un char pointeur
 * @src: est un char pointeur constant
 */
void _strcat(char *dest, const char *src)
{
	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';
}

/**
 * _strcpy - Permet de copier une chaîne de caractères (src)
 * dans une autre (dest), caractère par caractère, jusqu'à \0.
 * @dest: est un char pointeur
 * @src: est un char pointeur constant
 *
 * Return: Always char
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
