#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
/**
 * check_elf - test when a file be an ELF file.
 * @e_ident: the pointer to  array contain the ELF magic numbers.
 *
 * Description: when the file was not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int ind;

	for (ind = 0; ind < 4; ind++)
	{
		if (e_ident[ind] != 127 &&
		    e_ident[ind] != 'E' &&
		    e_ident[ind] != 'L' &&
		    e_ident[ind] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - the Prints magic numbers  an ELF header.
 * @e_ident: THe pointer to be an array contained the ELF magic numbers.
 *
 * Description: Magic numbers was separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int ind;

	printf(" Magic: ");

	for (ind = 0; ind < EI_NIDENT; ind++)
	{
		printf("%02x", e_ident[ind]);

		if (ind == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - the Prints class of an ELF header.
 * @e_ident: the  pointer to be  an array contained the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - THe  Prints  data of an ELF header.
 * @e_ident: The  pointer tobe an array containrd the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 *  * print_version - The Prints version of an ELF header.
 *   * @e_ident: The pointer tobe an array contained the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - The Prints OS/ABI of an ELF header.
 * @e_ident: The  pointer tobe an array contained the ELF version.
 */

