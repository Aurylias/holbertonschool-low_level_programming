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
	dog_t *new_dog;
	int len_name;
	int len_owner;

	for (len_name = 0; name[len_name]; len_name++)
	{}

	for (len_owner = 0; owner[len_owner]; len_owner++)
	{}

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->name = malloc(len_name);
	if (new_dog->name == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	new_dog->owner = malloc(len_owner);
	if (new_dog->owner == NULL)
	{
		free(new_dog->owner);
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	new_dog->name = name;
	new_dog->owner = owner;
	new_dog->age = age;

	return (new_dog);
}
