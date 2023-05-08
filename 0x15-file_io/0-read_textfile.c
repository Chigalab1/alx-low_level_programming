#include "main.h"

/**
 * read_textfile - a function that reads a text file and prints
 * it to the POSIX standard output
 * @filename: name of file to be read
 * @letters: number of letters
 * Return: the actual number of letters it could read and print or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t ff;
	ssize_t m;
	ssize_t n;
	char *buffer;

	ff = open(filename, O_RDONLY);
	if (ff == -1)
		return (0);
	buffer = malloc(sizeof(char) *letters);
	n = read(ff, buffer, letters);
	m = write(STDOUT_FILENO, buffer, n);

	free(buffer);
	close(ff);
	return (m);
}
