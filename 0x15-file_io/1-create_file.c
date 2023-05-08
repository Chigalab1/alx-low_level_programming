#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: pointer to the name of the file to create
 * @text_content: pointer to the strin to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int ff = 0;
	int m, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
		{
			length++;
		}
	}

	ff = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	m = write(ff, text_content, length);

	if (ff == -1)
		return (-1);
	if (m == -1)
		return (-1);

	close(ff);

	return (1);
}
