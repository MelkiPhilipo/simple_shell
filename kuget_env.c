#include "shell.h"

/**
 * c_uzirudf - a function that duplicates a string.
 * @uzi: a string that will be duplicated
 * @rt: the number of bytes to be excluded
 * Return: the string will be returned
 */
char *c_uzirudf(char *uzi, int rt)
{
	char *rudufisha_uzi;
	int rodh, ure = 0;

	if (uzi == NULL)
		return (NULL);

	while (*(uzi + ure))
		ure++;
	ure++;

	rudufisha_uzi = malloc(sizeof(char) * (ure - rt));
	if (rudufisha_uzi == NULL)
		return (NULL);

	rodh = 0;
	while (rodh < (ure - rt))
	{
		*(rudufisha_uzi + rodh) = *(uzi + rt + rodh);
		rodh++;
	}
	return (rudufisha_uzi);
}

/**
 * pata_env - a function that finds and returns a copy of the requested env var
 * @uzi: the string to store the env var in
 * @mzngr: whole set of the variables of the environment
 * Return: the copy of requested env var will be returned
 */
char *pata_env(char *uzi, list_t *mzngr)
{
	int s = 0, rt = 0;

	while (mzngr != NULL)
	{
		s = 0;
		while ((mzngr->var)[s] == uzi[s])
			s++;
		if (uzi[s] == '\0' && (mzngr->var)[s] == '=')
			break;
		mzngr = mzngr->inayofuata;
	}

	while (uzi[rt] != '\0')
		rt++;
	rt++;
	return (c_uzirudf(mzngr->var, rt));
}

