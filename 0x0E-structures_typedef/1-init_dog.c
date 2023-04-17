/**
 * init_dog - initializes a struct dog
 * @d: pointer to struct dog to initialize
 * @name: name to set in dog struct
 * @age: age to set in dog struct
 * @owner: owner to set in dog struct
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
