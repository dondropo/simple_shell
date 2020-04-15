#include "holberton.h"

/**
 * _prompt - prompt
 *
 * Return: read line
 */
void _prompt(void)
{

	if (isatty(STDIN_FILENO))
	{
		write(1, "Cisfun->$ ", 10);
	}
}
