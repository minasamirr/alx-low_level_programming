#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

/**
 * print_error - Print an error message to stderr and exit with
 * a specified code
 * @msg: The error message
 * @code: The exit code
 *
 * Return: (void)
 */
void print_error(char *msg, int code)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(code);
}

/**
 * copy_file - Copy the content of one file to another
 * @from_filename: The source filename
 * @to_filename: The destination filename
 *
 * Return: 0 on success, 97, 98, 99, or 100 on error
 */
int copy_file(const char *from_filename, const char *to_filename)
{
	int from_fd, to_fd, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	from_fd = open(from_filename, O_RDONLY);
	if (from_fd == -1)
	{
		print_error("Can't read from file", 98);
	}

	to_fd = open(to_filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		print_error("Can't write to file", 99);
	}

	while ((bytes_read = read(from_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			print_error("Can't write to file", 99);
		}
	}

	if (bytes_read == -1)
	{
		print_error("Can't read from file", 98);
	}

	if (close(from_fd) == -1)
	{
		print_error("Can't close fd", 100);
	}

	if (close(to_fd) == -1)
	{
		print_error("Can't close fd", 100);
	}

	return (0);
}
