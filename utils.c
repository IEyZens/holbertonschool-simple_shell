#include "shell.h"

/**
 * free_and_null - Libère un pointeur et le met à NULL
 * @ptr: double pointeur à libérer
 */
void free_and_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
