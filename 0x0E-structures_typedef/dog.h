#ifndef DOG_H
#define DOG_H
/**
 * struct dog - poppy
 * @name: poppy name
 * @age: poppy age
 * @owner: poppy owner
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
