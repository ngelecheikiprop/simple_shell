#include "shell.h"

/**
 * count_words - make a string into token
 * @str: the string to tokenize
 * @delim: what to use to tokenize
 *
 * Return: the number of words
 *
*/
size_t count_words(char *str, char *delim)
{
	size_t count = 0;
	char *token = NULL;
	char *local_copy;

	local_copy = strdup(str);
	token = strtok(local_copy, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		++count;
	}
	free(local_copy);
	free(token);
	return (count);
}

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
	if (size_of_array == 0)
	{
		return (NULL);
	}
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
