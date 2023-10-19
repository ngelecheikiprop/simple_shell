#include "shell.h"
/**
 * Allocate_New_Memory - Allocates new memeory for the substring.
 * @start: Pointer to the start of the substring.
 * @length: Length of the substring.
 * Return: A dynamically allocated substring.
 */
char *Allocate_New_Memory(const char *start, size_t length)
{
char *substring = malloc(length + 1);

if (substring == NULL)
{
perror("Failed to allocate memory");
exit(EXIT_FAILURE);
}

strncpy(substring, start, length);
substring[length] = '\0';
return (substring);
}

/**
 * substring_creation - Splits a string into substrings based on delimiters.
 * @str: Pointer to the input string.
 * Return: An array of dynamically allocated substrings.
 */
char **substring_creation(char *str)
{
static char *next_substring;
char *substring_start, *substring;
char **substrings = NULL;
size_t substring_count = 0, substring_length = 0;

if (str != NULL)
{
next_substring = str;
}
else if (next_substring == NULL)
{
return (NULL);
}
next_substring += strspn(next_substring, DELIMITERS);
if (*next_substring == '\0')
{
next_substring = NULL;
return (NULL);
}
while (*next_substring != '\0')
{
next_substring += strspn(next_substring, DELIMITERS);
if (*next_substring == '\0')
{
break;
}
substring_start = next_substring;
substring_length = strcspn(next_substring, DELIMITERS);
substring = Allocate_New_Memory(substring_start, substring_length);
substrings = realloc(substrings, (substring_count + 1) * sizeof(char *));
if (substrings == NULL)
{
perror("Failed to allocate memory");
exit(EXIT_FAILURE);
}
substrings[substring_count] = substring;
substring_count++;
next_substring += substring_length;
}
return (substrings);
}
