#ifndef DOG_G
#define DOG_G
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
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
