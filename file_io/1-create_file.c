#include "main.h"

/**
* create_file - Creates a file
*
* @filename: Tha name of the file to create
* @text_content: A string to write in the new file
*
* Return: 1 on success, -1 on failure
*/


int create_file(const char *filename, char *text_content)
{
	int file, len, char_count;

	if (!text_content)
		return (-1);

	file = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
	if (file == -1)
		return (-1);

	if (!text_content)
	{
		close(file);
		return (1);
	}

	len = strlen(text_content);
	char_count = write(file, text_content, len);

	if (char_count == -1 || (size_t)char_count != len)
		return (-1);

	close(file);
	return (1);
}
