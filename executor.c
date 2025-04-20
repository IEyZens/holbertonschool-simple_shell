#include "shell.h"

/**
 * parse_args - Permet d'exécuter des commandes avec arguments (ex : ls -l)
 * @command: est un char pointeur
 *
 * Return: Always char
 */
char **parse_args(char *command)
{
	char **argv = NULL, **temp;
	char *token;
	int i = 0, size = 8;

	argv = malloc(sizeof(char *) * size);
	if (argv == NULL)
		return (NULL);

	token = strtok(command, " ");
	while (token)
	{
		argv[i++] = token;

		if (i >= size)
		{
			size = size * 2;
			temp = realloc(argv, sizeof(char *) * size);
			if (temp == NULL)
			{
				free(argv);
				return (NULL);
			}

			argv = temp;
		}

		token = strtok(NULL, " ");
	}

	argv[i] = NULL;
	return (argv);
}

/**
 * execute_command - Lancement des commandes
 * @command: est un char pointeur
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char **argv;

	if (command == NULL || *command == '\0')
		return;

	argv = parse_args(command);
	if (argv == NULL || argv[0] == NULL)
	{
		free(argv);
		return;
	}

	if (access(argv[0], X_OK) != 0)
	{
		print_error();
		free(argv);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		write(STDERR_FILENO, "Error: fork failed\n", 19);
		free(argv);
		return;
	}

	if (pid == 0)
	{
		execve(argv[0], argv, environ);
		print_error();
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(argv);
	}
}
