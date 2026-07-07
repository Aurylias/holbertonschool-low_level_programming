#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_dog - Print all var for dog
* @d: Struct for the dog
* Return: None
*/

void print_dog(struct dog *d)
{
	printf("Name: %s", d->name);
	printf("Age : %f", d->age);
	printf("Owner: %s", d->owner);
}
