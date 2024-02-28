#include "shell.h"

/**
 * hesure - a function that counts a number of 0s in a tens power number
 * @h: hesabu or number
 * Return: a count or idadi of digits will be returned
 */
int hesure(int h)
{
	int idadi = 0;
	int hes = h;

	while (hes > 9 || hes < -9)
	{
		hes /= 10;
		idadi++;
	}
	return (idadi);
}
/**
 * integer_kwenda_string - a function that turns an integer into a string
 * @hesabu: integer au number nzima
 * Return: the integer as a string and NULL when failed
 */

char *integer_kwenda_string(int hesabu)
{
	int takwimu, kmis, rodh = 0, st = 0, ri;
	char *lif;

	takwimu = hesabu;
	kmis = 1;

	if (hesabu < 0)
		st = 1;
	lif = malloc(sizeof(char) * (hesure(takwimu) + 2 + st));
	if (lif == NULL)
		return (NULL);
	if (hesabu < 0)
	{
		lif[rodh] = '-';
		rodh++;
	}
	for (ri = 0; takwimu > 9 || takwimu < -9; ri++)
	{
		takwimu /= 10;
		kmis *= 10;
	}
	for (takwimu = hesabu; ri >= 0; ri--)
	{
		if (takwimu < 0)
		{
			lif[rodh] = (takwimu / kmis) * -1 + '0';
			rodh++;
		}
		else
		{
			lif[rodh] = (takwimu / kmis) + '0';
			rodh++;
		}
		takwimu %= kmis;
		kmis /= 10;
	}
	lif[rodh] = '\0';
	return (lif);
}

