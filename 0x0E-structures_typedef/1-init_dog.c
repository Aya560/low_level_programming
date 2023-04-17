#include "dog.h"

/**
 * init_dog - initializes a dog structure
 * @d: pointer to the dog structure to initialize
 * @name: name to initialize
 * @age: age to initialize
 * @owner: owner to initialize
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d != NULL)
    {
        d->name = name;
        d->age = age;
        d->owner = owner;
    }
}
