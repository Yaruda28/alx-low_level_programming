#include "main.h"

/**
 * append_text_to_file - Append the text a end of a files.
 * @filename: the pointer to a name of a files.
 * @text_content: A string to add the end of the files.
 *
 * Return: when the function failed or filename is NULL - -1.
 *        when a file did not exist  user lack writeing permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int p, x, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	x = write(p, text_content, len);

	if (p == -1 || x == -1)
		return (-1);

	close(p);

	return (1);
}

