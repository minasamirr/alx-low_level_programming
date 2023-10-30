#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * error_exit - Print an error message to stderr and exit with a specified code
 * @msg: The error message
 * @code: The exit code
 */
void error_exit(char *msg, int code)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(code);
}

/**
 * print_elf_header - Display information from the ELF header
 * @elf_header: Pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *elf_header)
{
	printf("ELF Header:\n");
	printf("\tMagic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00\n");
	printf("\tClass:                             ELF%d\n", elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
	printf("\tData:                              2's complement, %s endian\n",
	       elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");
	printf("\tVersion:                           1 (current)\n");
	printf("\tOS/ABI:                            UNIX - %s\n", elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "System V" : "Solaris");
	printf("\tABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("\tType:                              %s (Executable file)\n",
	       elf_header->e_type == ET_EXEC ? "EXEC" : "unknown");
	printf("\tEntry point address:               0x%lx\n", elf_header->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename", 98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Can't open file", 98);

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		error_exit("Can't read ELF header", 98);

	if (lseek(fd, 0, SEEK_SET) == -1)
		error_exit("Can't reset file offset", 98);

	print_elf_header(&elf_header);

	close(fd);
	return 0;
}
