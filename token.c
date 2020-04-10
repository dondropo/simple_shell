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
	int count_delim = 0;

	while (string[i] != '\0')
	{
		if (string[i] == *delim)
			count_delim++;
		i++;
	}
	array = malloc((count_delim + 2) * sizeof(char *));
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