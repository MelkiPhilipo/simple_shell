#include "shell.h"

/**
 * _uzicmp - a function that compares two strings
 * @z1: a string 1
 * @z2: a string 2
 * Return: an integer and 0  when exactly the same string
 */

int _uzicmp(char *z1, char *z2)
{
	int rodh = 0;

	while (*(z1 + rodh) == *(z2 + rodh) && *(z1 + rodh))
		rodh++;

	if (*(z2 + rodh))
		return (*(z1 + rodh) - *(z2 + rodh));
	else
		return (0);
}

