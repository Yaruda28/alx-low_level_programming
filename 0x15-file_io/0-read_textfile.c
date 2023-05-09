#include "main.h"
#include <stdlib.h>
/**
 * read_textfile- text file print to STDOUT.
 * @filename: text file be readable
 * @letters: numbers of letters will read
 * Return: w- actual numbers of bytes read and print
 *        0 when function fail or filename was NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *yar;
	ssize_t yd;
	ssize_t x;
	ssize_t u;

	yd = open(filename, O_RDONLY);
	if (yd == -1)
		return (0);
	yar = malloc(sizeof(char) * letters);
	u = read(yd, yar, letters);
	x = write(STDOUT_FILENO, yar, u);

	free(yar);
	close(yd);
	return (x);
}
