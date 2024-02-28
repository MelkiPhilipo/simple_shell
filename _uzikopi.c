#include "shell.h"

/**
 * _uzikopi - a function that copies the string pointed to by uziadd,
 * @htma: copies a string to this folder
 * @uziadd: this is the string to copy
 * Return: a copy of original strig will be returned
 */

char *_uzikopi(char *htma, char *uziadd)
{
	int rodh, ure;

	for (ure = 0; uziadd[ure] != '\0'; ure++)
		;

	for (rodh = 0; rodh <= ure; rodh++)
		htma[rodh] = uziadd[rodh];

	return (htma);
}

