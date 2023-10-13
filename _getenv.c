#include "shell.h"
/**
 * _getenv - get the variable given
 * @var: the variable to get
 * @env: where to look for the variable
 *
 * Return: the path or null if not found
 *
*/
char *_getenv(char *var, char **env)
{
	char *token;

	while (env)
	{
		token = strtok(*env, "=");
		if (strcmp(token, var) == 0)
		{
			return (strtok(NULL, "="));
		}
		++env;
	}
	return (NULL);
}
