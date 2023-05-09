#include "main.h"

/**
 * create_file - Created the file.
 * @filename: the pointer to the name of the files created.
 * @text_content: A pointer to a string to writes a files.
 *
 * Return: when a function is failed - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int yd, x, bnm = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (bmn = 0; text_content[bnm];)
			bnm++;
	}

	yd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(yd, text_content, bnm);

	if (yd == -1 || x == -1)
		return (-1);

	close(yd);

	return (1);
}

