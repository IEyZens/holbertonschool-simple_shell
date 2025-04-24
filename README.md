# README SIMPLE SHELL

Le projet ```Simple Shell``` consiste à reproduire différentes commandes du véritable shell.

## REQUIREMENTS

### General

Allowed editors: ```vi```, ```vim```, ```emacs```
All your files will be compiled on Ubuntu 20.04 LTS using ```gcc```, using the options ```-Wall -Werror -Wextra -pedantic -std=gnu89```
All your files should end with a new line
A ```README.md``` file, at the root of the folder of the project is mandatory
Your code should use the ```Betty``` style. It will be checked using ```betty-style.pl``` and ```betty-doc.pl```
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (```why?```)

## MAIN.C

```c
#include "shell.h"

/**
 * main - Boucle principale du shell
 *
 * Return: Always 0
 */
int main(void)
{
	/* Pointeur vers la chaîne qui contiendra la commande entrée par l'utilisateur */
	char *command;
	/* Variable utilisée pour itérer dans l'affichage des variables d'environnement */
	int i;

	/* Boucle infinie qui représente le coeur du shell */
	while (1)
	{
		/* Lecture de la commande entrée par l'utilisateur */
		command = read_command();

		/* Si la lecture échoue (ex : EOF reçu) */
		if (!command)
		{
			/* Si l'entrée standard est un terminal */
			if (isatty(STDIN_FILENO))
				/* Écrit un retour à la ligne pour le formatage */
				write(STDOUT_FILENO, "\n", 1);
			/* Sortie de la boucle principale */
			break;
		}

		/* Si l'utilisateur entre la commande "exit" */
		if (strcmp(command, "exit") == 0)
		{
			/* Libère la mémoire allouée à la commande */
			free(command);
			/* Sortie du shell */
			break;
		}

		/* Si l'utilisateur entre la commande "env" */
		if (strcmp(command, "env") == 0)
		{
			/* Parcours du tableau des variables d'environnement */
			for (i = 0; environ[i]; i++)
			{
				/* Affiche chaque variable */
				write(STDOUT_FILENO, environ[i], strlen(environ[i]));
				/* Retour à la ligne après chaque variable */
				write(STDOUT_FILENO, "\n", 1);
			}
			/* Libère la mémoire allouée à la commande "env" */
			free(command);
			/* Passe à l’itération suivante de la boucle */
			continue;
		}

		/* Si la commande n’est ni "exit" ni "env", elle est exécutée */
		execute_command(command);
		/* Libère la mémoire allouée à la commande après exécution */
		free(command);
	}

	/* Retourne 0 si succès */
	return (0);
}
```
Commande de compilation et d'éxecution :

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh
```

Commandes en mode interactif :
| Commandes            | Description                                                               |
| ----------------- | ------------------------------------------------------------------ |
./hsh | Ouverture du shell.
/bin/ls | Affiche une liste des fichiers en utilisant le chemin.
exit | Quitte le shell correctement.
ls | Affiche une liste des fichiers sans utiliser le chemin.
ls -l | Affiche une liste des fichiers en colonnes avec les permissions fichiers, le propriétaire du fichier, la date de création etc...
pwd | Afficher le nom complet du répertoire de travail actuel.
env | Affiche l'environnement actuel.

Commandes en mode non interactif :
| Commandes            | Description                                                               |
| ----------------- | ------------------------------------------------------------------ |
echo "ls" | Simule l'utilisateur tapant la commande "ls".
echo "/bin/ls" | Exécute la commande /bin/ls, sans passer par le $PATH.
echo "exit" | Exécute la commande "exit" en libérant la mémoire.
echo "env" | Exécute la commande "env" en affichant toutes les variables d'environnement.

## FLOWCHART

```mermaid
flowchart TD
	Start([Demarrage du programme])
	ReadCmd[Lire la commande - read_command]
	CmdNull{Commande est NULL}
	IsTTY{Entree interactive}
	PrintNewline[Afficher une nouvelle ligne]
	ExitLoop1[Sortir de la boucle]
	CmdExit{Commande est exit}
	FreeCmd1[Liberer la commande]
	CmdEnv{Commande est env}
	PrintEnv[Afficher les variables d'environnement]
	FreeCmd2[Liberer la commande]
	ContinueLoop[Continuer la boucle]
	ExecCmd[Executer la commande]
	FreeCmd3[Liberer la commande]
	End([Retourner 0 et quitter])

	Start --> ReadCmd
	ReadCmd --> CmdNull
	CmdNull -- Oui --> IsTTY
	IsTTY -- Oui --> PrintNewline --> ExitLoop1
	IsTTY -- Non --> ExitLoop1
	CmdNull -- Non --> CmdExit
	CmdExit -- Oui --> FreeCmd1 --> ExitLoop1
	CmdExit -- Non --> CmdEnv
	CmdEnv -- Oui --> PrintEnv --> FreeCmd2 --> ContinueLoop --> ReadCmd
	CmdEnv -- Non --> ExecCmd --> FreeCmd3 --> ReadCmd
	ExitLoop1 --> End
```

## EXEMPLES

```
#cisfun$ ls
# ➜ Affiche le contenu du répertoire

#cisfun$ ls -l
# ➜ Affiche les fichiers dans un dossier en mode détaillé

#cisfun$ /bin/echo Hello, world
# ➜ Affiche "Hello, world"

#cisfun$ env
# ➜ Affiche toutes les variables d’environnement

#cisfun$ exit
# ➜ Ferme le shell
```

## MAN PAGE
Man page de la commande exit : http://manpagesfr.free.fr/man/man3/exit.3.html
Man page de la commande ls : https://www.man-linux-magique.net/man1/ls.html
Man page de la commande pwd : https://www.man-linux-magique.net/man1/pwd.html
Man page de la commande env : http://manpagesfr.free.fr/man/man1/env.1.html

## AUTEURS
Thomas Roncin - https://github.com/IEyZens
