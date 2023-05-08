#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file
 * @filename: pointer to the name of the file
 * @text_content: a pointer to the string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int length = 0;
	int a, m = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
		{
			length++;
		}
	}

	a = open(filename, O_WRONLY | O_APPEND);
	m = write(a, text_content, length);

	if (a == -1)
		return (-1);
	if (m == -1)
		return (-1);

	close(a);

	return (1);
}
