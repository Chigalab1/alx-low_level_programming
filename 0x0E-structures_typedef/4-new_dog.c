#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - lenght of a string
 * @s: string parameter
 *
 * Return: the length of a string
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
/**
 * _strcpy - a function that copies a string poited by src
 * @dest: destination
 * @src: source
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int l;
	int i;

	i = 0;
	l = 0;

	while (src[l] != '\0')
	{
		l++;
	}
	while (i < l)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * new_dog - function that craetes a new dog
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 *
 * Return: pointer on success, else NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int l1;
	int l2;

	l1 = _strlen(name);
	l2 = _strlen(owner);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
	{
		return (NULL);
	}

	dog->name = malloc(sizeof(char) * (l1 + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = malloc(sizeof(char) * (l2 + 1));
	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL);
	}
	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}
