#include "fuction_pointers.h"
#include <stdio.h>
/**
 * print_name - funtion that prints name
 * @name: string to print
 * @f: pointer to function
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL)
		return;
	if (f == NULL)
		return;

	f(name);
}
