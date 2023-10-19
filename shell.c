#include "shell.h"
void trim_whitespace(char *str)
{
    int start = 0;
		int i = 0;
    int end = strlen(str) - 1;
    while (isspace(str[start])) 
		{
        start++;
    }
    if (start > end) 
		{
        str[0] = '\0';
        return;
    }
    while (end > start && isspace(str[end])) 
		{
        end--;
    }
    for (i = start; i <= end; i++) 
		{
        str[i - start] = str[i];
    }
    str[end - start + 1] = '\0';
}

/**
 * main -this is the entry point
 * @ac: this if the argument count
 * @av: this contain the arguments
 * @env: the environment variable
 *
 * Return: nothing
*/
int main(int ac, char **av)
{
	size_t count;
	char *buffer = NULL;
	char **argv;
	char *delim = " ";
	char *prompt = "$";

	(void)ac;
	(void)av;
	while (1)
	{
		buffer = NULL;
		count = 0;
		if (isatty(fileno(stdin)))
		{
		write(STDOUT_FILENO, prompt, 1);
		fflush(stdout);
		}
		if (getline(&buffer, &count, stdin) == EOF)
		{
			free(buffer);
			return (0);
		}
		trim_whitespace(buffer);
		argv = list_of_words(buffer, delim);
		if (argv == NULL)
		{
			continue;
		}
		if (_getfunc(argv[0]))
		{
			exec_builtin(argv);
		}
		else if (file_exists(argv))
		{
			exec_external(argv);
		}
		else
		{
			fprintf(stderr, "%s: 1: %s: not found\n", av[0], argv[0]);
			return (1);
		}
		free(argv);
	}
	return (0);
}
