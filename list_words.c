#include "shell.h"
/**
 * list_of_words - creates a list of words from string
 * @str: the word
 * @delim:what is dividing the words
 *
 * Return: array of words
*/
char **list_of_words(char *str, char *delim)
{
	size_t size_of_array;
	char **argv;
	char *token;
	int i = 0;

	size_of_array = count_words(str, delim);
	argv = malloc((sizeof(char *) * size_of_array) + 1);
	token = strtok(str, delim);
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	free(token);
	return (argv);
}
