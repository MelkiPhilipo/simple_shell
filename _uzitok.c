#include "shell.h"

/**
 * t_uziure - a function that returns string length of token for mallocing
 * @uzi: a token
 * @naf: the index position in the command typed by user into shell
 * @chamb: delimeter (e.g. " ");
 * Return: the length of the token
 */
int t_uziure(char *uzi, int naf, char chamb)
{
	int ure = 0;

	while ((uzi[naf] != chamb) && (uzi[naf] != '\0'))
	{
		naf++;
		ure++;
	}
	return (ure);
}

/**
 * t_ukubwa - a function that returns number of delim ignoring continuous delim
 * @uzi: the command typed by user into shell
 * @chamb: the delimeter
 * Return: the number of delims will be returned
 */
int t_ukubwa(char *uzi, char chamb)
{
	int rodh = 0, num_chamb = 0;

	while (uzi[rodh] != '\0')
	{
		if ((uzi[rodh] == chamb) && (uzi[rodh + 1] != chamb))
		{
			num_chamb++;
		}
		if ((uzi[rodh] == chamb) && (uzi[rodh + 1] == '\0'))
		{
			num_chamb--;
		}
		rodh++;
	}
	return (num_chamb);
}

/**
 * ignore_chamb - a function that returns without preceeding delims
 * @uzi: the string
 * @chamb: the delimiter
 * Return: new string will be returned
 */
char *ignore_chamb(char *uzi, char chamb)
{
	while (*uzi == chamb)
		uzi++;
	return (uzi);
}

/**
 * _uzi_tok - the function that tokenizes a string
 * @uzi: the command that user typed into shell
 * @chamb: the delimeter
 * Return: an array of tokens will be returned
 */
char **_uzi_tok(char *uzi, char *chamb)
{
	int folderukubwa = 0, nt = 0, zi = 0, rodh = 0, ure = 0, ze = 0, st = 0;
	char **tokes = NULL, s_kr;

	s_kr = chamb[0];
	uzi = ignore_chamb(uzi, s_kr);
	folderukubwa = t_ukubwa(uzi, s_kr);
	tokes = malloc(sizeof(char *) * (folderukubwa + 2));
	if (tokes == NULL)
		return (NULL);
	while (uzi[ze] != '\0')
		ze++;
	while (zi < ze)
	{
		if (uzi[zi] != s_kr)
		{
			ure = t_uziure(uzi, zi, s_kr);
			tokes[nt] = malloc(sizeof(char) * (ure + 1));
			if (tokes[nt] == NULL)
				return (NULL);
			rodh = 0;
			while ((uzi[zi] != s_kr) && (uzi[zi] != '\0'))
			{
				tokes[nt][rodh] = uzi[zi];
				rodh++;
				zi++;
			}
			tokes[nt][rodh] = '\0';
			st++;
		}
		if (zi < ze && (uzi[zi + 1] != s_kr && uzi[zi + 1] != '\0'))
			nt++;
		zi++;
	}
	nt++;
	tokes[nt] = NULL;
	return (tokes);
}

