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
	if (d == NULL)
	{

	}
	else
	{
		if (d->name == NULL)
		{
			printf("Name: (nil)");
		}
		else
		{
			printf("Name: %s", d->name);
		}

		printf("Age: %f", d->age);

		if (d->owner == NULL)
		{
			printf("Name: (nil)");
		}
		else
		{
			printf("Owner: %s", d->owner);
		}
	}
}
