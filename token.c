#include "holberton.h"
/**
 *words_counter - counts the words into the input
 *
 *@s: pointer to count words
 *
 *Return: w value
 */
int words_counter(char *s)
{
	int i, w = 0, is_word = 0;

	for (i = 0; s[i]; i++)
	{
		if (is_word == 0 && (s[i] != ' ' && s[i] != '\n'
					&& s[i] != '\t' && s[i] != '\r'))
		{
			w++;
			is_word = 1;
		}
		else if (is_word == 1 && (s[i] == ' ' || s[i] == '\n'
					|| s[i] == '\t' || s[i] == '\r'))
		{
			is_word = 0;
		}
	}
	return (w);
}
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

	array = malloc((words_counter(string) + 1) * sizeof(char *));
	if (array == NULL)
	{
		perror("El array es nulo");
		exit(1);
	}
	pnt = _strdup(string);
	token = strtok(pnt, delim);
	i = 0;
	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
	free(token);
	return (array);
}
