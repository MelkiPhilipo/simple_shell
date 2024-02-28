#include "shell.h"

/**
 * frii_dabo_ptr - a function that frees malloced arrays
 * @uzi: the array of strings
 */
void frii_dabo_ptr(char **uzi)
{
	int rodh = 0;

	while (uzi[rodh] != NULL)
	{
		free(uzi[rodh]);
		rodh++;
	}
	free(uzi);
}

