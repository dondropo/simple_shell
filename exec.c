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
	__pid_t pid;
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
			printf("permission denied\n");
		}
		return (0);
	}
	printf("command not found\n");

	return (0);
}
