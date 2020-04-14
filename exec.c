#include "holberton.h"

int execute(char **arguments)
{
    //char *argv[] = {"/bin/ls", "-la", "/home/joer9514/projects/simple_shell", NULL};

    if (execve(arguments[0], arguments, NULL) == -1)
    {
        perror("Command not found:");
    }
    return (0);
}

int main(__attribute__((unused)) int ac, char **av)
{
    __pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("Error");
        exit(1);
    }
    if (pid == 0)
    {
        execute(av);
    }
    else
    {
        wait(&status);
    }
    
    return (0);
}