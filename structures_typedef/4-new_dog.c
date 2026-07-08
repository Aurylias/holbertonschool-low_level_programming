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
	int name_cpy;
	int owner_cpy;

	for (name_cpy = 0; name[name_cpy]; name_cpy++)
	{}

	for (owner_cpy = 0; owner[owner_cpy]; owner_cpy++)
	{}

	n_dog = malloc(sizeof(dog_t));
	if (n_dog == NULL)
	{
		free(n_dog);
		return (NULL);
	}

	n_dog->name = malloc(name_cpy);
	if (n_dog->name == NULL)
	{
		free(n_dog->name);
		free(n_dog);
		return (NULL);
	}

	n_dog->owner = malloc(owner_cpy);
	if (n_dog->owner == NULL)
	{
		free(n_dog->owner);
		free(n_dog->name);
		free(n_dog);
		return (NULL);
	}

	n_dog->name = name;
	n_dog->owner = owner;
	n_dog->age = age;

	return (n_dog);
}
