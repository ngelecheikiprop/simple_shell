#include "shell.h"
char *file_info(char **args)
{
    char *env_var_name = "PATH";
    char *path = my_getenv(env_var_name);
    char *token;
    char *full_path = (char *)malloc(1024);

    if (full_path == NULL)
    {
      return (NULL);
    }

    if (path == NULL)
    {
        fprintf(stderr, "PATH environment variable not found.\n");
        return (NULL);
    }
    token = strtok(path, ":");
    while (token != NULL)
    {
        snprintf(full_path, 1024, "%s/%s", token, args[0]);
        if (access(full_path, F_OK) == 0)
        {
            return (full_path);
        }
        token = strtok(NULL, ":");
    }

    free(full_path);
    return (NULL);
}


/*int main(void)
{
  char *args[10] = {"/bin/ls"};
  char *file_stat = file_info(args);
  if (file_stat != NULL) {
      printf("%s", file_stat);
  } else {
      printf("File information not found.\n");
  }
  return (0);
}*/