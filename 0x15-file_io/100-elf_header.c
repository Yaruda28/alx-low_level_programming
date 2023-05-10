#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_class(unsigned char e_ident[]);
void print_data(unsigned char e_ident[]);
void print_version(unsigned char e_ident[]);
void print_osabi(unsigned char e_ident[]);
void print_type(unsigned int e_type, unsigned char e_ident[]);
void print_entry(unsigned long int e_entry, unsigned char e_ident[]);
void check_elf(unsigned char e_ident[]);

int main(int argc, char *argv[])
{
    int fd;
    unsigned char e_ident[EI_NIDENT];
    Elf32_Ehdr header;

    if (argc < 2) {
        printf("Usage: %s <elf-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    /* read the first bytes into the e_ident array to identify it as an ELF file */
    if (read(fd, e_ident, EI_NIDENT) < EI_NIDENT) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    /* check if the file is an ELF file */
    check_elf(e_ident);

    /* seek to the beginning of the file and read the ELF header */
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    /* print the ELF header information */
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_type(header.e_type, header.e_ident);
    print_entry(header.e_entry, header.e_ident);

    close(fd);
    return 0;
}

/**
 * check_elf - checks if the file is an ELF file
 * @e_ident: the array containing the ELF magic numbers
 */
void check_elf(unsigned char e_ident[])
{
    if (memcmp(e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: not an ELF file\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * print_class - prints the class of an ELF header
 * @e_ident: the array containing the ELF class
 */
void print_class(unsigned char e_ident[])
{
    printf(" Class: ");
    switch (e_ident[EI_CLASS]) {
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
 * print_data - prints the data encoding of an ELF header
 * @e_ident: the array containing the ELF data encoding
 */
void print_data(unsigned char e_ident[])
{
    printf(" Data: ");
    switch (e_ident[EI_DATA]) 
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n
}
