#include "shell.h"
/**
 * _getdir - gets the directories in path
 *
 * @h: where to look
 * @command: the command to look for
 *
 * Return: WHere the path was found
 * --------NULL if path was not found
*/
char *_getdir(dir_node *h, char *command)
{
	char *final_path;
	struct stat st;


	while (h != NULL)
	{
		final_path = strdup(h->dir);
		strcat(final_path, "/");
		strcat(final_path, command);
		if (stat(final_path, &st) == 0)
		{
			return (final_path);
		}
		h = h->next_dir;
	}
	return (NULL);
}
