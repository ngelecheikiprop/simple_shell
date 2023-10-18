#include "my_shell.h"
/**
 * exec - execute a command
 * @argv: the array of commands
 * @env: the environment
 * @av: argument vector
 *
 * Return: nothing
*/
void exec(char **argv, char **env, char **av)
{
pid_t child;
int status;
child = fork();
if (child == 0)
{
if (execve(argv[0], argv, env) == -1)
{
perror(av[0]);
}
}
else
{
waitpid(child, &status, 0);
free(argv);
}
}
