#include "main.h"

char *create_buf(char *filename);
void file_close(int ff);

/**
 * create_buf - function that allocates bytes to a buffer
 * @filename: name of file
 *
 * Return: pointer to the allocated buffer
 */
char *create_buf(char *filename)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buf);
}

/**
 * file_close - function that closes file descriptors
 * @file_d: file descriptor
 */
void file_close(int file_d)
{
	int i;

	i = close(file_d);

	if (i == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close file_d %d\n", file_d);

		exit(100);
	}
}

/**
 * main - a program that copies the content of a file
 * to another file
 * @argc: number of argumenta
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int src, dest;
	int y, m;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,
			"Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buf(argv[2]);
	src = open(argv[1], O_RDONLY);
	y = read(src, buf, 1024);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src == -1 || y == -1)
		{
			dprintf(STDERR_FILENO,
				 "Error: Can't read src file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		m = write(dest, buf, y);
		if (dest == -1 || m == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write dest %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		y = read(src, buf, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);

	} while (y > 0);

	free(buf);
	file_close(src);
	file_close(dest);

	return (0);
}

