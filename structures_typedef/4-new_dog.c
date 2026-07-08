#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int len_name;
	int len_owner;
	int i;

	for (len_name = 0; name[len_name]; len_name++)
	{}

	for (len_owner = 0; owner[len_owner]; len_owner++)
	{}

	n_dog = malloc(sizeof(dog_t));
	if (n_dog == NULL)
	{
		free(n_dog);
		return (NULL);
	}

	n_dog->name = malloc(len_name);
	if (n_dog->name == NULL)
	{
		free(n_dog->name);
		free(n_dog);
		return (NULL);
	}

	n_dog->owner = malloc(len_owner);
	if (n_dog->owner == NULL)
	{
		free(n_dog->owner);
		free(n_dog->name);
		free(n_dog);
		return (NULL);
	}

	n_dog->name = name_cpy;
	n_dog->owner = owner_cpy;
	n_dog->age = age;

	return (n_dog);
}
