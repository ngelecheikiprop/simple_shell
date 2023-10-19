#include "shell.h"

/**
 * sh_exit - prompts the shell to exit
 * @args: a double pointer to an array of arguments
 * Return: Always 0
*/
int hsh_exit(char **args)
{
  int status_code = 0;
  if (args[1] != NULL)
  {
    status_code = atoi(args[1]);
    if (status_code >= 0)
    {
      exit(status_code);
    }
    else
    {
      fprintf(stderr, "Illegal number: %s\n",args[1]);
    }
  }
  else
  {
    exit(0);
  }
  return (0);
}

/**
 * sh_cd - change directories
 * @args: a double pointer to an array of arguments
 * Return: Always 0 or 1
*/
int hsh_cd(char **args)
{
  char *dir, *key = "HOME";
  char *cwd = malloc(_PC_PATH_MAX);
  if (cwd == NULL)
  {
    return (1);
  }
  if (args[1] == NULL || (strcmp(args[1], "~") == 0))
  {
    dir = getenv(key);
    if (chdir(dir) != 0)
    {
      free(cwd);
      return (1);
    }
  }
  else 
  {
    dir = args[1];
    if (chdir(dir) != 0)
    {
      free(cwd);
      return (1);
    }
  }
  if (getcwd(cwd, sizeof(cwd)) == NULL)
  {
    free(cwd);
    return (1);
  }
  if (setenv("PWD", cwd, 1) == -1)
  {
    free(cwd);
    return (1);
  }
  free(cwd);
  return (0);
}

int hsh_env(char **args) 
{
    char **env = environ;
    (void)args;

    while (*env != NULL)
    {
      puts(*env);
      env++;
    }

    return (0);
}

/*int hsh_setenv(char **args)
{
  int i = 0;
  char **env = environ;
  char *node_envar_dup, *envar, *key, *key_concat;
  char *value = NULL;
  env_list *node = create_list(env);

  if (node == NULL)
  {
    fprintf(stderr, "Failed to create list\n");
    return (1);
  }

  while (*args != NULL)
  {
    args++;
    i++;
  }

  if (*args == NULL || i < 3)
  {
    fprintf(stderr, "setenv KEY VALUE\n");
    return -1;
  }

  while (node != NULL)
  {
    node_envar_dup = strdup(node->envar);
    key = strtok(node_envar_dup, "=");
    if (key == args[1])
    {
      value = strtok(NULL, "=");
      value = args[2];
    }
    node = node->next_node;
  }
  key_concat = strcat(args[1], "=");
  envar = strcat(key_concat, value);
  add_node_end(&node, envar);
  printf("it works\n");
  free_list(node);
  return (0);
}*/


/*int hsh_unsetenv(char **args)
{
  if (*args == NULL || args < 2)
  {
    fprintf(stderr, "unsetenv KEY\n");
  }
}


int hsh_env() {
    char **env = environ;

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}*/
