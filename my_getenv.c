#include "shell.h"



/*int set_path(void)char *_getenv(const char *name);
{
    char **env = environ;
    const char *desiredKey = "PATH"; // Replace with the key you want to isolate
    size_t desiredKeyLength = strlen(desiredKey);

    while (*env != NULL) {
        if (strncmp(*env, desiredKey, desiredKeyLength) == 0 && (*env)[desiredKeyLength] == '=') {
            // Found the desired key
            printf("Value of %s is %s\n", desiredKey, *env + desiredKeyLength + 1);
            break; // You can break out of the loop if you've found the key
        }
        env++;
    }

    return 0;
}
*/

char *my_getenv(const char *desiredkey) {
    char **env = environ;
    size_t desiredKeyLength = strlen(desiredkey);
    char *value = NULL;
    char *copy;

    while (*env != NULL) {
        if (strncmp(*env, desiredkey, desiredKeyLength) == 0 && (*env)[desiredKeyLength] == '=')
        {
            value = malloc(strlen(*env + desiredKeyLength + 1) + 1);
            strcpy(value, *env + desiredKeyLength + 1);
            break;
        }
        env++;
    }

    if (value != NULL)
    {
        copy = malloc(strlen(value) + 1);
        if (copy != NULL)
        {
            strcpy(copy, value);
        }
        free(value);
    }
    return (copy);
}


/*char *_getenvars(const char *desiredkey, const char *appendValue) {
    char **env = environ;
    size_t desiredKeyLength = strlen(desiredkey);
    size_t new_value_length;
    char *value = NULL;

    while (*env != NULL) {
        if (strncmp(*env, desiredkey, desiredKeyLength) == 0 && (*env)[desiredKeyLength] == '=') {
            value = malloc(strlen(*env + desiredKeyLength + 1) + 1);
            strcpy(value, *env + desiredKeyLength + 1);
            break;
        }
        env++;
    }

    if (value != NULL) {
        new_value_length = strlen(value) + strlen(appendValue) + 1;
        value = realloc(value, new_value_length);
        if (value == NULL)
        {
            return (NULL);
        }
        strcat(value, appendValue);

        return (value);
    }
    else 
    {
        return (NULL);
    }
}
*/

