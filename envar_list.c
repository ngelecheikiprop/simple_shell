#include "shell.h"
void free_list(env_list *head)
{
  env_list *current = head;
  env_list *next;

  while (current != NULL)
  {
    next = current->next_node;
    free(current->envar);
    free(current);
    current = next;
  }
}

/**
 * create_list - makes a linked list from the path directories
 * @env: the environment variable to look into
 *
 * Return: the begining of the list
 */

env_list *create_list(char **env)
{
  env_list *head;
  char *list;
	char *env_copy = strdup(*env);

  head = NULL;
  list = strtok(env_copy, "\n");
  while (list)
  {
    add_node(&head, list);
		list = strtok(NULL, "\n");
  }
  return (head);
}
/**
 * add_node - Adds a new node at the beginning of a list.
 * @head: A pointer to the head of the linked list.
 * @args: The string to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
 
env_list *add_node(env_list **head, char *str)
{
	env_list *new_node;
	new_node = malloc(sizeof(env_list));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->envar = strdup(str);
	if (new_node->envar == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next_node = *head;

	*head = new_node;
	return (new_node);
}


