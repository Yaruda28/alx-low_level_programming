#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: the name of the file to append to
 * @text_content: a NULL terminated string to add to the end of the file
 *
 * Return: 1 on success, -1 on failure (file does not exist or insufficient
 *         permissions to write to the file)
 */
int append_text_to_file(const char *filename, char *text_content)
{
  int fd, result, text_len = 0;

  if (filename == NULL)
    return (-1);

  if (text_content != NULL) {
    while (text_content[text_len] != '\0')
      text_len++;
  }

  fd = open(filename, O_WRONLY | O_APPEND);
  if (fd == -1)
    return (-1);

  if (text_len > 0) {
    result = write(fd, text_content, text_len);
    if (result == -1) {
      close(fd);
      return (-1);
    }
  }

  close(fd);

  return (1);
}
