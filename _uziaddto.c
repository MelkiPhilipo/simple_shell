#include "shell.h"

/**
 * _uziaddto - a fuction that concatenates two strings
 * @htma: a string to be added to
 * @uziadd: a string to add
 * Return: an added string will be returned
 */
char *_uziaddto(char *htma, char *uziadd)
{
	int ure = 0;
	int ure2 = 0;
	int jumla_ure = 0;
	int s = 0;

	while (htma[ure] != '\0')
	{
		ure++;
		jumla_ure++;
	}
	while (uziadd[ure2] != '\0')
	{
		ure2++;
		jumla_ure++;
	}

	htma = _urealloc(htma, ure, sizeof(char) * jumla_ure + 1);

	while (uziadd[s] != '\0')
	{
		htma[ure] = uziadd[s];
		ure++;
		s++;
	}
	htma[ure] = '\0';

	return (htma);
}

