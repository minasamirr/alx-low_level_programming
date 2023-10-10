#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * new_dog - Creates a new dog with specified attributes.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the newly created dog_t structure, or NULL on failure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog_ptr;

	new_dog_ptr = malloc(sizeof(dog_t));

	if (new_dog_ptr == NULL)
	{
		return (NULL);
	}

	int name_length = 0;
	int owner_length = 0;

	while (name[name_length] != '\0')
		name_length++;

	while (owner[owner_length] != '\0')
		owner_length++;

	new_dog_ptr->name = malloc((name_length + 1) * sizeof(char));
	new_dog_ptr->owner = malloc((owner_length + 1) * sizeof(char));

	if (new_dog_ptr->name == NULL || new_dog_ptr->owner == NULL)
	{
		free(new_dog_ptr->name);
		free(new_dog_ptr->owner);
		free(new_dog_ptr);
		return (NULL);
	}

	for (int i = 0; i <= name_length; i++)
	{
		new_dog_ptr->name[i] = name[i];
	}

	for (int i = 0; i <= owner_length; i++)
	{
		new_dog_ptr->owner[i] = owner[i];
	}

	new_dog_ptr->age = age;

	return (new_dog_ptr);
}
