#include "holberton.h"
/**
 *execute - executes a command
 *
 *@cmd: double pointer for argument value
 *@av: arguments
 *@cmd_num: command number
 *
 *Return: returns to 0
 */

int execute(char **cmd, char *av, int cmd_num)
{
	pid_t pid = 0;
	int status = 0;
	struct stat st;

	if (stat(cmd[0], &st) == 0)
	{
		if (access(cmd[0], X_OK) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("Error");
				exit(1);
			}
			if (pid == 0)
			{
				execve(cmd[0], cmd, NULL);
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			dprintf(STDERR_FILENO, "%s: %d: %s: permission denied\n"
			, av, cmd_num, cmd[0]);
		}
		return (0);
	}
	else
	{
		dprintf(STDERR_FILENO, "%s: %d: %s: command not found\n"
		, av, cmd_num, cmd[0]);
	}
	return (0);
}
