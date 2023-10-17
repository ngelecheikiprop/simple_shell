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
    add_node_end(&head, list);
		list = strtok(NULL, "\n");
  }
  free(env_copy);
  return (head);
}
/**
 * add_node_end - Adds a new node at the end of a list.
 * @head: A pointer to the head of the linked list.
 * @args: The string to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
env_list *add_node_end(env_list **head, char *str)
{
env_list *new_node;
env_list *last;

new_node = malloc(sizeof(new_node));
if (new_node == NULL)
{
return (NULL);
}

new_node->envar = strdup(str);
new_node->next_node = NULL;

if (*head == NULL)
{
*head = new_node;
return (new_node);
}

last = *head;
while (last->next_node != NULL)
{
last = last->next_node;
}
last->next_node = new_node;
return (new_node);
}

/*int print_list(env_list *head)
{
	env_list *current = head;

	while (current != NULL)
	{
	if (current->envar != NULL)
	{
	printf("%s\n", current->envar);
	}
	current = current->next_node;
	}
	return (0);
}

int main(void)
{
  char **env = environ;
  print_list(create_list(env));
  return (0);
}*/