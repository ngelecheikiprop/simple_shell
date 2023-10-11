#include "shell.h"

/*char *env(void)
{
    char *key = "PATH";
    char *path = my_getenv(key, "PATH=");
    char **path_directories = NULL;
    char *dir;
    int i = 0;

    char *temp = strdup(path);
    char *token = strtok(temp, ":");
    while (token != NULL)
    {
        i++;
        token = strtok(NULL, ":");
    }
    free(temp);

    path_directories = (char **)malloc((i + 1) * sizeof(char *));
    if (path_directories == NULL)
    {
        return (NULL);
    }

    dir = strtok(path, ":");

    while (dir != NULL)
    {
        path_directories[i] = strdup(dir);
        dir = strtok(NULL, ":");
		i++;
    }
    path_directories[i] = NULL;
    return (path);
}
*/

/*int main(void)
{
    char *result = path();
    printf("%s", result);
    return (0);
}
*/