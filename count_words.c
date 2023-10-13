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
