#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
* init_dog - Initialize a variable
* @d: Pointeur to a struct
* @name: pointeur to the name var in d
* @age: pointeur to the age var in d
* @owner: pointeur to the owner var in d
* Retunr: None
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		printf("Ok");
		exit(1);
	d->name = name;
	d->age = age;
	d->owner = owner;
}
