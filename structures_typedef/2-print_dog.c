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
		if (d_name == NULL)
		{
			printf("Name: (nil)");
		}
		printf("Name: %s", d_name);

		if (d_age == NULL)
		{
			printf("Age: (nil)");
		}
		else
		{
			printf("Age: %f", d->age);
		}

		if (d_owner == NULL)
		{
			printf("Name: (nil)");
		}
		printf("Owner: %s", d_owner);
	}
}
