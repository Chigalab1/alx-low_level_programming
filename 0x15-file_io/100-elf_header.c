#include "main.h"

void elf_check(unsigned char *el);
void magic_print(unsigned char *el);
void class_print(unsigned char *el);
void data_print(unsigned char *el);
void version_print(unsigned char *el);
void abi_print(unsigned char *el);
void os_abi_print(unsigned char *el);
void type_print(unsigned int elf_type, unsigned char *el);
void entry_print(unsigned long int elf_entry, unsigned char *el);
void elf_close(int elf);

/**
 * elf_check - function that checks if a file is an ELF file
 * @el: array containg ELF numbers
 *
 */
void elf_check(unsigned char *el)
{
	int idx = 0;

	while (idx < 4)
	{
		if (el[idx] != 127 && el[idx] != 'E' &&
			el[idx] != 'L' && el[idx] != 'F')
		{
			dprint(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		idx++;
	}
}

/**
 * magic_print - a function that prints magic numbers of an ELF header
 * @el: array containing the ELF magic numbers
 */
void magic_print(unsigned char *el)
{
	int idx = 0;

	printf("  Magic:   ");

	while (idx < EI_NIDENT)
	{
		printf("%02x", el[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");

		idx++;
	}
}

/**
 * class_print - a function that prints the class of an ELF header
 * @el: arry containing the ELF class
 */
void class_print(unsigned char *el)
{
	printf("  Class:                             ");

	switch (el[EI_CLASS])
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
		printf("<unknown: %x>\n", el[EI_CLASS]);
	}
}

/**
 * data_print - a function that prints the data of an  ELF header
 * @el: array containing the ELF class
 */
void data_print(unsigned char *el)
{
	printf("  Data:                              ");

	switch (el[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", el[EI_CLASS]);
	}
}

/**
 * version_print - a function that prints the version of an ELF header
 * @el: an array containing the ELF version
 */
void version_print(unsigned char *el)
{
	printf("  Version:                           %d",
			el[EI_VERSION]);

	switch (el[EI_VERSION])
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
 * @el: pointer to an array containing the version of ELF
 */
void os_abi_print(unsigned char *el)
{
	printf("  OS/ABI:                            ");
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
		printf("<unkown: %x>\n", el[EI_OSABI]);
	}
}

/**
 * abi_print - a function that prints the ABI version of an ELF header
 * @el: array containg the ELF version
 */
void print_abi(unsigned char *el)
{
	printf("  ABI Version:                       %d\n",
				el[EI_ABIVERSION]);
}

/**
 * type_print - a function that prints the type of an ELF header
 * @elf_type: ELF type
 * @el: pointer to an array containing ELF class
 */

void type_print(unsigned int elf_type, unsigned char *el)
{
	if (el[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type:                              ");

	switch (elf_type)
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
 * @elf_entry: EFL entry point
 * @el: array containg the EFL class
 */

void entry_print(unsigned long int elf_entry, unsigned char *el)
{
	printf("  Entry point address:               ");

	if (el[EI_DATA] == ELFDATAMSB)
	{
		elf_entry = ((elf_entry << 9) & 0xFF00FF00) |
			((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (el[EI_CLASS] == ELFCLASS32)
		printf("%#\n", (unsigned int)elf_entry);
	else
		printf("%x\n", elf_entry);
}

/**
 * elf_close function that closes an EFL file
 * @elf: file descriptor
 */

void elf_close(int elf)
{
	if (close(elf) == -1)
	{
		dprint(STDERR_FILENO,
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
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int a, int y;

	a = open(argv[1], O_RDONLY);
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	y = read(a, header, sizeof(Elf64_Ehdr));
	if (Y == -1)
	{
		free(HEADER);
		elf_close(0);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_check(header->el);
	printf("ELF Header:\n");
	magic_print(header->el);
	class_print(header->el);
	data_print(header->el);
	version_print(header->el);
	os_abi_print(header->el);
	abi_print(header->el);
	type_print(header->elf_type, header->el);
	entry_print(header->elf_entry, header->el);

	free(header);
	elf_close(a);
	return (0);
}
