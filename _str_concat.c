#include "holberton.h"
#include <stdlib.h>
/**
 * str_concat - concatenate two strings
 * @s1: string 1
 * @s2: string 2
 * Return: char type
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, h, k;
	char *conc;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i]; i++)
	{
	}
	for (j = 0; s2[j]; j++)
	{
	}
	conc = malloc(sizeof(char) * (i + j + 1));

	if (conc == NULL)
		return (NULL);
	for (k = 0; k < i; j++, k++)
	{
		conc[k] = s1[k];
	}
	for (h = i, k = 0; h < j; h++, k++)
	{
		conc[h] = s2[k];
	}
	conc[h] = '\0';
	return (conc);
}
