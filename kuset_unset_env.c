#include "shell.h"

/**
 * tafuta_mzngr - a function which finds given env var in linked list
 * @mzngr: the linked list of variable of the environment
 * @uzi: the name of the variable
 * Return: an index of node in linked list will be returned
 */
int tafuta_mzngr(list_t *mzngr, char *uzi)
{
	int r = 0, faharisi = 0;

	while (mzngr != NULL)
	{
		r = 0;
		while ((mzngr->var)[r] == uzi[r])
			r++;
		if (uzi[r] == '\0')
			break;
		mzngr = mzngr->inayofuata;
		faharisi++;
	}
	if (mzngr == NULL)
		return (-1);
	return (faharisi);
}

/**
 * _ondoapangaenv - a function which removes node
 * @mzngr: the list which linked
 * @uzi: the command typed by user eg unsetenv MAIL
 * Return: Always 0 will be returned on success
 */
int _ondoapangaenv(list_t **mzngr, char **uzi)
{
	int faharisi = 0, r = 0;

	if (uzi[1] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		frii_dabo_ptr(uzi);
		return (-1);
	}
	faharisi = tafuta_mzngr(*mzngr, uzi[1]);
	frii_dabo_ptr(uzi);
	if (faharisi == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	r = futa_nodeint_kwenye_faharisi(mzngr, faharisi);
	if (r == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * _pangaenv - a function which creates or modifys existing env var
 * @mzngr: the list which is linked
 * @uzi: a command typed in by user
 * Return: Always 0 when success and 1 when fails
 */
int _pangaenv(list_t **mzngr, char **uzi)
{
	int faharisi = 0, r = 0;
	char *addto;
	list_t *shika;

	if (uzi[1] == NULL || uzi[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		frii_dabo_ptr(uzi);
		return (-1);
	}
	addto = _uzirudf(uzi[1]);
	addto = _uziaddto(addto, "=");
	addto = _uziaddto(addto, uzi[2]);
	faharisi = tafuta_mzngr(*mzngr, uzi[1]);
	if (faharisi == -1)
	{
		ongeza_mwisho_node(mzngr, addto);
	}
	else
	{
		shika = *mzngr;
		while (r < faharisi)
		{
			shika = shika->inayofuata;
			r++;
		}
		free(shika->var);
		shika->var = _uzirudf(addto);
	}
	free(addto);
	frii_dabo_ptr(uzi);
	return (0);
}

