#include "shell.h"

/**
 * _urealloc - a function that allocates memory and sets all values to 0
 * @onyeshi: a pointer to the memory that allocated at previous
 * @ukubwa_zamani: the size allocated at previous
 * @ukubwa_mpya: a new size to be reallocated
 * Return: a pointer to reallocated memory will be returned
 */

void *_urealloc(void *onyeshi, unsigned int ukubwa_zamani,
		unsigned int ukubwa_mpya)
{
	void *nt;
	unsigned int rodh;

	if (ukubwa_mpya == 0 && onyeshi != NULL)
	{
		free(onyeshi);
		return (NULL);
	}

	if (ukubwa_mpya == ukubwa_zamani)
		return (onyeshi);

	if (onyeshi == NULL)
	{
		nt = malloc(ukubwa_mpya);
		if (nt == NULL)
			return (NULL);
		else
			return (nt);
	}

	nt = malloc(ukubwa_mpya);
	if (nt == NULL)
		return (NULL);

	for (rodh = 0; rodh < ukubwa_zamani && rodh < ukubwa_mpya; rodh++)
		*((char *)nt + rodh) = *((char *)onyeshi + rodh);
	free(onyeshi);

	return (nt);
}

