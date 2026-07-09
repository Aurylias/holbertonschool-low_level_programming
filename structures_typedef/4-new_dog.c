#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
* new_dog - Create a new dog
* @name: Name of the dog
* @age: Age of the dog
* @owner: Owner of the dog
* Return: A new dog
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *n_dog;
	int len_name, len_owner;

	for (len_name = 0; name[len_name]; len_name++)
	{}

	for (len_owner = 0; owner[len_owner]; len_owner++)
	{}

	n_dog = (int *) malloc(sizeof(dog_t));
	if (n_dog == NULL)
	{
		return (NULL);
	}

	n_dog->name = (int *) malloc(len_name);
	if (n_dog->name == NULL)
	{
		free(n_dog);
		return (NULL);
	}

	n_dog->owner = (int *) malloc(len_owner);
	if (n_dog->owner == NULL)
	{
		free(n_dog->name);
		free(n_dog);
		return (NULL);
	}

	n_dog->name = name;
	n_dog->owner = owner;
	n_dog->age = age;

	return (n_dog);
}
