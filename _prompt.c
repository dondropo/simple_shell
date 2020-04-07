#include "holberton.h"

/**
 * _prompt - prompt
 * @error: error case
 * Return: read line
 */
int _prompt(int error)
{
	char *buff;
	size_t buff_size = 0;
	int x;
	__pid_t ppid;

	ppid = getppid();
	while (1)
	{
		printf("$ ");
		x = getline(&buff, &buff_size, stdin);
		printf("%s", buff);
		if (x == -1)
		{
			break;
		}
	}
	return (ppid);
}
