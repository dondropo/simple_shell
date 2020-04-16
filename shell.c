#include "holberton.h"

/**
 * main - shell
 * @ac: length arguments
 * @av: arguments
 * Return: int
 */
int main(int ac, char **av)
{
	char *buffer = av[1];
	size_t buffer_size = ac;
	int infinite = 1;
	char **aux = NULL;
	int i = 0;

	do {
		_prompt();
		if (getline(&buffer, &buffer_size, stdin) != EOF)
		{
			i++;
			if (check_buffer(buffer))
			{
				aux = token(buffer, " \n\t\r");
				execute(aux, av[0], i);
				free_aux(aux);
			}
		}
		else
		{
			exit(0);
		}
		/*free(buffer);*/
	} while (infinite);
	free(buffer);
	free_aux(aux);
	return (0);
}
/**
 *check_buffer - checker for buffer
 *
 *@buffer: buffer
 *
 *Return: returns an int
 */
int check_buffer(char *buffer)
{
	int i;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ' && buffer[i] != '\n')
		{
			if (buffer[i] != '\t' && buffer[i] != '\r')
			{
				return (1);
			}
		}
	}
	return (0);
}
/**
 *free_aux - frees axiliar var
 *
 *@aux: auxiliar var
 *
 *Return: void
 */
void free_aux(char **aux)
{
	free(aux[0]);
	free(aux);
}
