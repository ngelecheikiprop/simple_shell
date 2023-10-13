#include "shell.h"

/**
 * sh_exit - prompts the shell to exit
 * @args: a double pointer to an array of arguments
 * Return: Always 0
*/
int hsh_exit(char **args)
{
  (void)args;
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
  char cwd[1024];
  if (args[1] == NULL || (strcmp(args[1], "~") == 0))
  {
    dir = my_getenv(key);
    chdir(dir);
    printf("it worked\n");
  }
  else 
  {
    dir = args[1];
    chdir(dir);
    printf("it worked again\n");
  }
  if (getcwd(cwd, sizeof(cwd)) == NULL)
  {
    perror("getcwd");
    return (1);
  }
  if (setenv("PWD", cwd, 1) == -1)
  {
    perror("setenv");
  }
  return (0);
}


/*int hsh_env() {
    char **env = environ;

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}*/
