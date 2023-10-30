#include "main.h"

/**
 * append_text_to_file - Append text to the end of a file
 * @filename: The name of the file
 * @text_content: The text content to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fileDescriptor, openFlags, writeResult;
	ssize_t textLen = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	openFlags = O_WRONLY | O_APPEND;

	fileDescriptor = open(filename, openFlags);

	if (fileDescriptor == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		textLen = strlen(text_content);
		writeResult = write(fileDescriptor, text_content, textLen);

		if (writeResult == -1 || writeResult != textLen)
		{
			close(fileDescriptor);
			return (-1);
		}
	}

	close(fileDescriptor);
	return (1);
}
