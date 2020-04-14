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

    do
    {
        _prompt();
        if (getline(&buffer, &buffer_size, stdin) != EOF)
        {
            write(1, buffer, buffer_size);
        }
        else
        {
            return (buffer_size);
        }
    } while (infinite);
    free(buffer);
    return (0);
}