#include "shell.h"

/**
 * c_uziaddto - a function that with ignoring first character '~' in cd,
 * concatenates two strings.
 * @htma: holds a string that will be added to
 * @uziadd: a string to add
 * Return: A string that would be concatenated
 */
char *c_uziaddto(char *htma, char *uziadd)
{
	int ure = 0;
	int ure2 = 0;
	int jumla_ure = 0;
	int r = 0;

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

	r = 1;
	while (uziadd[r] != '\0')
	{
		htma[ure] = uziadd[r];
		ure++;
		r++;
	}
	htma[ure] = '\0';

	return (htma);
}

/**
 * c_pangaenv - a function that set environment and concatetes string before
 * @mzngr: holds the linked list of the environment variable
 * @jina: the name of the variable of the environment
 * @dirpath: The path of the directory
 * Return: Always 0 when success
 */
int c_pangaenv(list_t **mzngr, char *jina, char *dirpath)
{
	int faharisi = 0, r = 0;
	char *addto;
	list_t *shika;

	addto = _uzirudf(jina);
	addto = _uziaddto(addto, "=");
	addto = _uziaddto(addto, dirpath);
	faharisi = tafuta_mzngr(*mzngr, jina);

	shika = *mzngr;
	while (r < faharisi)
	{
		shika = shika->inayofuata;
		r++;
	}
	free(addto);
	return (0);
}

/**
 * cd_tu - a function that makes a move from directory to home
 * @mzngr: takes in a linked list of environment
 * @yasasa: takes in a directory that is currently at working
 */
void cd_tu(list_t *mzngr, char *yasasa)
{
	char *nyumbani = NULL;

	nyumbani = pata_env("HOME", mzngr);
	c_pangaenv(&mzngr, "OLDPWD", yasasa);
	free(yasasa);
	if (access(nyumbani, F_OK) == 0)
		chdir(nyumbani);
	yasasa = NULL;
	yasasa = getcwd(yasasa, 0);
	free(yasasa);
	free(nyumbani);
}

/**
 * cd_utekelezaji - kutekeleza the cd
 * @mzngr: takes in linked list of the environment
 * @yasasa: takes in the directory that is currently at working
 * @dirpath: takes in the path of the directory to chaange to
 * @uzi: takes in the first argument in order to write out an error
 * @hes: takes in the number of the line to write out an error
 * Return: Always 0 when success and 2 when fails
 */
int cd_utekelezaji(list_t *mzngr, char *yasasa, char *dirpath, char *uzi,
		int hes)
{
	int d = 0;

	if (access(dirpath, F_OK) == 0)
	{
		c_pangaenv(&mzngr, "OLDPWD", yasasa);
		free(yasasa);
		chdir(dirpath);
		yasasa = NULL;
		yasasa = getcwd(yasasa, 0);
		c_pangaenv(&mzngr, "PWD", yasasa);
		free(yasasa);
	}
	else
	{
		haiwezi_kucd_kwenye(uzi, hes, mzngr);
		free(yasasa);
		d = 2;
	}
	return (d);
}

/**
 * _cd - a function that changes directory
 * @uzi: a string typed in by user
 * @mzngr: linked list of the environment to retrieve paths (HOME and OLDPWD)
 * @hes: the user command of the certain number to be used at error message
 * Return: Always 0 when success and 2 when fails
 */
int _cd(char **uzi, list_t *mzngr, int hes)
{
	char *yasasa = NULL, *dirpath = NULL;
	int kutoka_stat = 0;

	yasasa = getcwd(yasasa, 0);
	if (uzi[1] != NULL)
	{
		if (uzi[1][0] == '~')
		{
			dirpath = pata_env("HOME", mzngr);
			dirpath = c_uziaddto(dirpath, uzi[1]);
		}
		else if (uzi[1][0] == '-')
		{
			if (uzi[1][1] == '\0')
				dirpath = pata_env("OLDPWD", mzngr);
		}
		else
		{
			if (uzi[1][0] != '/')
			{
				dirpath = getcwd(dirpath, 0);
				dirpath = _uziaddto(dirpath, "/");
				dirpath = _uziaddto(dirpath, uzi[1]);
			}
			else
				dirpath = _uzirudf(uzi[1]);
		}
		kutoka_stat = cd_utekelezaji(mzngr, yasasa, dirpath, uzi[1], hes);
		free(dirpath);
	}
	else
		cd_tu(mzngr, yasasa);
	frii_dabo_ptr(uzi);
	return (kutoka_stat);
}

