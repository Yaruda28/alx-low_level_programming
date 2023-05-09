#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int yd);
/**
 * create_buffer - allocate 1024 bytes for the buffers.
 * @file: A name of the file buffers be storing chars for.
 *
 * Return: a pointers to the newly-allocates buffers.
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
 * close_file - closed files descriptor.
 * @fd: the files descriptor  make closed.
 */
void close_file(int yd)
{
	int m;

	m = close(yd);

	if (m == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't closed yd %d\n", yd);
		exit(100);
	}
}

/**
 * If file_to or file_from cannot be closed - exit code 100.
 * If file_to cannot be created or written to - exit code 99.
 * If file_from does not exist or cannot be read - exit code 98.
 * Description: If the argument count is incorrect - exit code 97.
 */
int main(int argc, char *argv[])
{
	int to, nm, t, x;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	to = open(argv[1], O_RDONLY);
	t = read(from, buffer, 1024);
	nm = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (to == -1 || t == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		x = write(nm, buffer, t);
		if (nm == -1 || x == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		t = read(to, buffer, 1024);
		nm = open(argv[2], O_WRONLY | O_APPEND);

	} while (t > 0);

	free(buffer);
	close_file(to);
	close_file(nm);

	return (0);
}
