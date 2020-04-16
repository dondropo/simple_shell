#include "holberton.h"

/**
 * token - function to split strings with a specific delimiter
 * @string: text string for analysis
 * @delim: delimiter to separate
 * Return: array
 */
char **token(char *string, const char *delim)
{
	char *token;
	char **array;
	char *pnt;
	int i = 0;
	int hay_palabra = 0, j = 0;

	while (string[i] != '\0')
	{
		if (hay_palabra == 0 && (string[i] != ' ' || string[i] != '\n'))
			hay_palabra = 1, j++;
		else if (hay_palabra == 1 && (string[i] == ' ' || string[i] == '\n'))
			hay_palabra = 0;
		i++;
	}
	array = malloc((j + 1) * sizeof(char *));
	if (array == NULL)
	{
		perror("El array es nulo");
		exit(1);
	}
	pnt = strdup(string);
	token = strtok(pnt, delim);
	i = 0;
	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
	return (array);
}
