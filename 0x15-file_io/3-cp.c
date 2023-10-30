#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#define BUFSIZE 1024

/**
 * close_fd - Close a file descriptor
 * @fd: The file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * error_exit - Print an error message and exit with the given code
 * @code: The exit code
 * @format: The error message format
 */
void error_exit(int code, char *format, ...)
{
	va_list args;

	va_start(args, format);
	dprintf(STDERR_FILENO, format, args);
	va_end(args);
	exit(code);
}

/**
 * main - Copy the content of one file to another file
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, num_bytes;
	char buffer[BUFSIZE];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2]);

	while ((num_bytes = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		if (write(fd_to, buffer, num_bytes) != num_bytes)
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	if (num_bytes == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}

