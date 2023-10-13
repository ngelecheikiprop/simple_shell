#include "shell.h"
/**
 * _path_list - makes a linked list from the path directories
 *
 * @path: where the directories are
 * @env: the environment variable to look into
 *
 * Return: the begining of the list
 *
*/
dir_node *_path_list(char **env)
{
	char *path;
	dir_node *head;
	char **list_of_dir;

	head = NULL;
	path = _getenv("PATH", env);
	list_of_dir = list_of_words(path, ":");
	while (*list_of_dir)
	{
		add_node(&head, *list_of_dir);
		list_of_dir++;
	}
	return (head);
}
/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: A pointer to the head of the linked list.
 * @dir: The string to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dir_node *add_node(dir_node **head, const char *dir)
{
	dir_node *new_dir;

	if (dir == NULL)
		return (NULL);
	new_dir = malloc(sizeof(dir_node));
	if (new_dir == NULL)
	{
		return (NULL);
	}
	new_dir->dir = strdup(dir);
	if (new_dir->dir == NULL)
	{
		free(new_dir);
		return (NULL);
	}
	new_dir->next_dir = *head;

	*head = new_dir;
	return (new_dir);
}
