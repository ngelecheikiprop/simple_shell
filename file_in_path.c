#include "shell.h"
char *file_exists(char **args)
{
    char *env_var_name = "PATH";
    char *path = getenv(env_var_name);
    char *path_copy = strdup(path);
    char *token, *full_path;
    size_t path_size;
    if (path == NULL)
    {
        perror("PATH environment variable not found");
        free(path_copy);
        return (NULL);
    }

    if (args[0] != NULL && access(args[0], F_OK) == 0)
    {
        free(path_copy);
        return (args[0]);
    }

    token = strtok(path_copy, ":");
    path_size = strlen(token) + strlen(args[0]) + 2;
    full_path = (char *)malloc(path_size);
    if (full_path == NULL)
    {
        free(path_copy);
        return (NULL);
    }
    while (token != NULL)
    {
        snprintf(full_path, path_size, "%s/%s", token, args[0]);
        if (access(full_path, F_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }
        token = strtok(NULL, ":");
    }
    free(path_copy);
    free(full_path);
    return (NULL);
}


/*int main(void)
{
  char *args[10] = {"/bin/ls"};
  char *file_stat = file_exists(args);
  if (file_stat != NULL) {
      printf("%s", file_stat);
  } else {
      printf("File information not found.\n");
  }
  return (0);
}*/