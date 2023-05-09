#include "main.h"

/**
 * create_file - Creates the files.
 * @filename: the pointers to a names of a files to created.
 * @text_content: the pointers a string to write to a files.
 *
 * Return: when the function failed - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int yd, x, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	yd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(yd, text_content, len);

	if (yd == -1 || x == -1)
		return (-1);

	close(yd);

	return (1);
}
