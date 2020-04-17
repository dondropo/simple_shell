#include "holberton.h"

/**
 * strtok1 - tokens
 * @string: string
 * @delim: delimiter
 * Return: int
 */
int strtok1(char *string, char *delim)
{
	int i = 0, j = 0;

	while (string[i] != 0)
	{
		while (delim[j] != 0)
		{
			if (string[i] == delim[j])
				break;
			j++;
		}
		if (delim[j] == 0)
			break;
		i++;
	}
	return (i);
}

/**
 * strtok2 - tokens
 * @string: string
 * @delim: delimiter
 * Return: int
 */
int strtok2(char *string, char *delim)
{
	int i = 0, j = 0;

	while (string[i] != 0)
	{
		while (delim[j] != 0)
		{
			if (string[i] == delim[j])
				break;
			j++;
		}
		if (delim[j] != 0)
			break;
		i++;
	}
	return (i);
}
/**
 * _strtok - tokens
 * @string: string
 * @delim: delimiter
 * Return: int
 */
char *_strtok(char *string, char *delim)
{
	static char *sv;
	int i = 0;
	char *tmp_s;
	char *tmp_d;

	if (string == 0)
		string = sv;
	if (string == 0)
		return (0);

	tmp_s = string;
	tmp_d = delim;

	i = strtok1(tmp_s, tmp_d);
	string = string + i;
	if (*string == 0)
	{
		sv = string;
		return (0);
	}
	tmp_s = tmp_s + i;
	i = strtok2(tmp_s, tmp_d);
	sv = tmp_s;
	if (tmp_s[i] != 0)
	{
		sv = (sv + i + 1);
		tmp_s[i] = '\0';
	}
	else
	{
		sv = '\0';
	}
	return (tmp_s);
}
