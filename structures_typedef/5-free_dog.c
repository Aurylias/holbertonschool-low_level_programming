#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
* free_dog - Free dogs
* @d: Dog to set free
* Return: None
*/

void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d->age);
	free(d);
}
