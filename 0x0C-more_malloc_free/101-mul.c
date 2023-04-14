#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_len - Finds the length of a string.
 * str: The string to be measured.
 * 
 * Return: The length of the string.
 */
int find_len(char *str)
{
	int l = 0;

	while (*str++)
		l++;

	return (l);
}

/**
 * create_xarray - craete an array of charges abd initialize of to l
 * @size: size of array
 *
 * Return: pointer fo the array
 */
char *create_xarray(int size)
{
	char *array;

