#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * main - displays information contained in the ELF header
 * @argc: number of command-line arguments
 * @argv: array of pointers to command-line arguments
 *
 * Return: 0 on success, otherwise 98 for wrong ELF file format or other errors
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr ehdr;
	int fd, rd;
	unsigned int i;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]), exit(98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Cannot read %s\n", argv[1]), exit(98);

	rd = read(fd, &ehdr, sizeof(ehdr));
	if (rd != sizeof(ehdr))
		dprintf(STDERR_FILENO, "Error: Cannot read %s\n", argv[1]), exit(98);

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr.e_ident[i]);
	printf("\n");
	if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
	    ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
	    ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
	    ehdr.e_ident[EI_MAG3] != ELFMAG3)
		dprintf(STDERR_FILENO, "Error: Not an ELF file - it has the wrong magic bytes at the start\n"), exit(98);

	printf("Class:                             %s\n", ehdr.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
	       (ehdr.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "Unknown"));
	printf("Data:                              %s\n", ehdr.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
	       (ehdr.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Unknown"));
	printf("Version:                           %d%s\n", ehdr.e_ident[EI_VERSION], ehdr.e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf("OS/ABI:                            ");
	switch (ehdr.e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		puts("UNIX - System V");
		break;
	case ELFOSABI_HPUX:
		puts("UNIX - HP-UX");
		break;
	case ELFOSABI_NETBSD:
		puts("UNIX - NetBSD");
		break;
	case ELFOSABI_LINUX:
		puts("UNIX - Linux");
		break;
	case ELFOSABI_SOLARIS:
		puts("UNIX - Solaris");
		break;
	case ELFOSABI_IRIX:
		puts("UNIX - IRIX");
		break;
	case ELFOSABI_FREEBSD:
		puts("UNIX - FreeBSD");
		break;
	case ELFOSABI_TRU64:
		puts("UNIX - TRU64");
		break;
	case ELFOSABI_ARM:
		puts("ARM");
		break;
	case ELFOSABI_STANDALONE:
		puts("Standalone App");
		break;
	default:
		puts("UNIX - Unknown");
		break;
	}

	printf("ABI Version:                       %d\n", ehdr.e_ident[EI_ABIVERSION]);
	printf("Type:                              %

