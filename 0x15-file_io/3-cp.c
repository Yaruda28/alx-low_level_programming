#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int yd);

/**
 * create_buffer - Allocate 1024 byte for buffer.
 * @file: A name of  files bufferbe storing chars for.
 *
 * Return: The pointer to newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closed file descriptor.
 * @yd: the file descriptor is closed.
 */
void close_file(int yd)
{
	int v;

	v = close(yd);

	if (v == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close yd %d\n", yd);
		exit(100);
	}
}

/**
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * main - Copies the contents of a file to another file.
 *
 * Return: 0 on success.
 *
 * If file_to or file_from cannot be closed - exit code 100.
 * If file_to cannot be created or written to - exit code 99.
 * If file_from does not exist or cannot be read - exit code 98.
 * Description: If the argument count is incorrect - exit code 97.
 */
int main(int argc, char *argv[])
{
	int from, to, g, x;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	g = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || g == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

                x = write(to, buffer, r);
		if (to == -1 || x == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		g = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (g > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

