#include "shell.h"

/**
 * _uzirudf - a function that returns a pointer to a newly allocated space,
 * @uzi: a string to be duplicated
 * Return: A pointer to duplicated string in the memory allocated.
 */
char *_uzirudf(char *uzi)
{
	char *rudufisha_uzi;
	int rodh, ure = 0;

	if (uzi == NULL)
		return (NULL);

	while (*(uzi + ure))
		ure++;
	ure++;

	rudufisha_uzi = malloc(sizeof(char) * ure);
	if (rudufisha_uzi == NULL)
		return (NULL);

	rodh = 0;
	while (rodh < ure)
	{
		*(rudufisha_uzi + rodh) = *(uzi + rodh);
		rodh++;
	}

	return (rudufisha_uzi);
}

