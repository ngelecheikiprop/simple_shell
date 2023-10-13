#include "shell.h"

BuiltinCommand commands[] = 
{
    {"cd", &hsh_cd},
    {"exit", &hsh_exit},
};

const int builtin_size = sizeof(commands) / sizeof(BuiltinCommand);
/**
 * builtin_comp - determines whether args is a builtin function
 * @args: double pointer to args
 * Return: 0 0r 1
*/
int builtin_comp(char **args)
{
    int i;
        
    for (i = 0; i < builtin_size; i++)
    {
        if (strcmp(args[0], commands[i].name) == 0)
        {
            return ((*commands[i].function)(args));
        }
    }

    return (1);
}
