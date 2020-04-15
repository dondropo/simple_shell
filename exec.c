#include "holberton.h"
/**
 *execute - executes a command
 *
 *@av: double pointer for argument value
 *
 *Return: returns to 0
 */

int execute(char **av)
{
	pid_t pid = 0;
	int status = 0;
	struct stat st;

	if (stat(av[1], &st) == 0)
	{
		if (access(av[1], X_OK) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("Error");
				exit(1);
			}
			if (pid == 0)
			{
				execve(av[1], av, NULL);
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			write(1, "permission denied\n", 19);
		}
		return (0);
	}
	else
	{
		write(1, "command not found\n", 19);
	}
	return (0);
}