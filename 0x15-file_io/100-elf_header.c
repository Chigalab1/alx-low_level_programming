#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void elf_check(unsigned char *e_ident);
void magic_print(unsigned char *e_ident);
void class_print(unsigned char *e_ident);
void data_print(unsigned char *e_ident);
void version_print(unsigned char *e_ident);
void abi_print(unsigned char *e_ident);
void os_abi_print(unsigned char *e_ident);
void type_print(unsigned int e_type, unsigned char *e_ident);
void entry_print(unsigned long int e_entry, unsigned char *e_ident);
void elf_close(int elf);

/**
 * elf_check - function that checks if a file is an ELF file
 * @e_ident: array containg ELF numbers
 *
 */
void elf_check(unsigned char *e_ident)
{
	int idx = 0;

	while (idx < 4)
	{
		if (e_ident[idx] != 127 && e_ident[idx] != 'E' &&
			e_ident[idx] != 'L' && e_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		idx++;
	}
}

/**
 * magic_print - a function that prints magic numbers of an ELF header
 * @e_ident: array containing the ELF magic numbers
 */
void magic_print(unsigned char *e_ident)
{
	int idx = 0;

	printf("  Magic:   ");

	while (idx < EI_NIDENT)
	{
		printf("%02x", e_ident[idx]);

		if (idx == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
		idx++;
	}
}

/**
 * class_print - a function that prints the class of an ELF header
 * @e_ident: arry containing the ELF class
 */
void class_print(unsigned char *e_ident)
{
	printf("  Class:                             ");

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
 * data_print - a function that prints the data of an  ELF header
 * @e_ident: array containing the ELF class
 */
void data_print(unsigned char *e_ident)
{
	printf("  Data:                              ");

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
 * version_print - a function that prints the version of an ELF header
 * @e_ident: an array containing the ELF version
 */
void version_print(unsigned char *e_ident)
{
	printf("  Version:                           %d",
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
 * os_abi_print - a function that prints the OS and ABI of an ELF header
 * @e_ident: pointer to an array containing the version of ELF
 *
 */
void os_abi_print(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unkown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * abi_print - a function that prints the ABI version of an ELF header
 * @e_ident: array containg the ELF version
 */
void abi_print(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
				e_ident[EI_ABIVERSION]);
}

/**
 * type_print - a function that prints the type of an ELF header
 * @e_type: ELF type
 * @e_ident: pointer to an array containing ELF class
 */

void type_print(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * entry_print -a function that prits point of ELF header
 * @e_entry: EFL entry point
 * @e_ident: array containg the EFL class
 */

void entry_print(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 9) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%x#\n", (unsigned int)e_entry);
	else
		printf("%lx\n", e_entry);
}

/**
 * elf_close - function that closes an EFL file
 * @elf: file descriptor
 *
 * Description: exit if the file cannot be closed
 */

void elf_close(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - program that displays the information contained in the
 * ELF header at the start of an ELF file
 * @argc: argument count
 * @argv: argument vector
 *
 * Description: exit the function if the file is not an EFL file
 *
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int a, y;

	a = open(argv[1], O_RDONLY);
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_close(a);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	y = read(a, header, sizeof(Elf64_Ehdr));
	if (y == -1)
	{
		free(header);
		elf_close(a);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_check(header->e_ident);
	printf("ELF Header:\n");
	magic_print(header->e_ident);
	class_print(header->e_ident);
	data_print(header->e_ident);
	version_print(header->e_ident);
	os_abi_print(header->e_ident);
	abi_print(header->e_ident);
	type_print(header->e_type, header->e_ident);
	entry_print(header->e_entry, header->e_ident);

	free(header);
	elf_close(a);
	return (0);
}
