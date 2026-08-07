#include "main.h"

/**
* read_textfile - Reads a text file and prints it
*
* @filename: The name of the file to read
* @letters: The number of letters to read and print
*
* Return: The number the actual number of letter read and printed
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file, char_count, read_file;
	char *buffer;

	buffer = (char *)malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);

	file = open(filename, O_RDONLY);
	if (!file)
	{
		free(buffer);
		return (0);
	}

	read_file = read(file, buffer, letters);
	if (read_file == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}

	char_count = write(STDOUT_FILENO, buffer, read_file);
	if (char_count == -1 || char_count != read_file)
	{
		free(buffer);
		close(file);
		return (0);
	}
	
	free(buffer);
	close(file);
	return (char_count);
}
