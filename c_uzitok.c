#include "shell.h"

/**
 * c_t_ukubwa - A function that returns a number of the string delim.
 * @uzi: The command typed into shell by the user
 * @chamb: The delimeter itself
 * Return: The number of tokens will be returned  of delimiting
 */
int c_t_ukubwa(char *uzi, char chamb)
{
	int rodh = 0, num_chamb = 0;

	if (uzi == NULL)
		return (0);
	while (uzi[rodh] != '\0')
	{
		if (uzi[rodh] == chamb)
		{
			num_chamb++;
		}
		rodh++;
	}
	return (num_chamb);
}


/**
 * c_uzi_tok - tokenizes a string even the continuous delim with empty string
 * @uzi: user's command typed into shell
 * @chamb: delimeter (e.g. " ");
 * Return: an array of tokens
 */
char **c_uzi_tok(char *uzi, char *chamb)
{
	int folderukubwa = 0, nt = 0, zi = 0, i = 0, ure = 0, ze = 0;
	char **tokes = NULL, s_kr;

	if (uzi == NULL)
		return (NULL);
	s_kr = chamb[0];
	folderukubwa = c_t_ukubwa(uzi, s_kr);
	tokes = malloc(sizeof(char *) * (folderukubwa + 2));
	if (tokes == NULL)
		return (NULL);

	while (uzi[ze] != '\0')
		ze++;
	while (zi < ze)
	{
		ure = t_uziure(uzi, zi, s_kr);
		tokes[nt] = malloc(sizeof(char) * (ure + 1));
		if (tokes[nt] == NULL)
			return (NULL);
		i = 0;
		while ((uzi[zi] != s_kr) &&
		       (uzi[zi] != '\0'))
		{
			tokes[nt][i] = uzi[zi];
			i++;
			zi++;
		}
		tokes[nt][i] = '\0';
		nt++;
		zi++;
	}
	tokes[nt] = NULL;
	return (tokes);
}

