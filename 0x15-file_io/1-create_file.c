#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * create_file - creates a file with the specified permissions and writes a
 *               string to it, or creates an empty file if no string is provided
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file, or NULL to
 *                create an empty file
 *
 * Return: 1 on success, -1 on failure (file can not be created, file can not
 *         be written, write "fails", etc...)
 */
int create_file(const char *filename, char *text_content)
{
  int fd, result, text_len = 0;

  if (filename == NULL)
    return (-1);

  if (text_content != NULL) {
    while (text_content[text_len] != '\0')
      text_len++;
  }

  fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
  if (fd == -1)
    return (-1);

  if (text_len > 0) {
    result = write(fd, text_content, text_len);
    if (result == -1)
      return (-1);
  }

  close(fd);

  return (1);
}
