#include "dog.h"

/**
 * print_dog - Prints the contents of a dog structure.
 * @d: Pointer to a struct dog.
 *
 * Description: This function prints the details of a struct dog,
 * including its name, age, and owner.
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", d->name != NULL ? d->name : "(nil)");
		printf("Age: %.6f\n", d->age);
		printf("Owner: %s\n", d->owner != NULL ? d->owner : "(nil)");
	}
}
