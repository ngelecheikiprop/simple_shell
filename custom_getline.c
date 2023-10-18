#include "shell.h"

/**
 * allocate_buffer - Allocates memory for a new line buffer.
 * @buffer: Pointer to the buffer to be allocated.
 * @bufsize: Pointer to the buffer size.
 */
void allocate_buffer(char **buffer, size_t *bufsize)
{
if (*buffer == NULL || *bufsize == 0)
{
*bufsize = STDIN_BUFFSIZE;
*buffer = (char *)malloc(*bufsize);

if (*buffer == NULL)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}
}
}

/**
 * read_from_stream - Read a line from a stream.
 *
 * @linepointer: Pointer to a buffer where the line will be stored.
 * @bufsize: Pointer to the buffer size.
 * @stream: Stream from which the line is read.
 * Return: The size of the read line.
 */
ssize_t read_from_stream(char **linepointer, size_t *bufsize, FILE *stream)
{
size_t position = 0;
int c;

allocate_buffer(linepointer, bufsize);


while (1)
{
c = fgetc(stream);

if (c == EOF || c == '\n')
{
  (*linepointer)[position] = '\0';

  if (position == 0 && c == EOF)
  {
  return (-1);
  }
  else
  {
  return (position);
  }
}

(*linepointer)[position] = (char)c;
position++;

if (position >= *bufsize)
{
  *bufsize = position * 2;
  *linepointer = (char *)realloc(*linepointer, *bufsize);

  if (*linepointer == NULL)
  {
  perror("Memory allocation failed");
  exit(EXIT_FAILURE);
  }
}

}
}
