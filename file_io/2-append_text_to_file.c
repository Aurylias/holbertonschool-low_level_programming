#include "main.h"

/**
* append_text_to_file - Appends text at the end of a file
*
* @filename: The name of the file to edit
* @text_content: A string to append at the end of the file
*
* Return: 1 on success, otherwise -1
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, char_count, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	len = strlen(text_content);
	char_count = write(fd, text_content, len);
	close(fd);

	if (char_count == -1 || char_count != len)
		return (-1);
	return (1);
}
