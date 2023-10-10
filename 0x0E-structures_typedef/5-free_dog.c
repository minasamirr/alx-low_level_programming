#include "dog.h"
#include <stdio.h>

/**
 * free_dog - Frees memory allocated for a dog structure.
 * @d: Pointer to a dog_t structure.
 *
 * Description: This function frees the memory allocated for a dog_t structure,
 * including the memory for the name and owner strings.
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
