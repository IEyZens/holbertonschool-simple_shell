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
	char **argv, *path;

	if (!command || *command == '\0')
		return;

	argv = parse_args(command);
	if (!argv || !argv[0])
	{
		free(argv);
		return;
	}

	path = resolve_path(argv[0]);
	if (!path)
	{
		print_error(argv[0]);
		free(argv);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		write(STDERR_FILENO, "Error: fork failed\n", 19);
		clean_and_return(path, argv, argv[0]);
		return;
	}

	if (pid == 0)
		run_child_process(path, argv);

	waitpid(pid, &status, 0);
	clean_and_return(path, argv, argv[0]);
}

