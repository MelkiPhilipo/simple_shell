#include "shell.h"

/**
 * _niwhich - fleshes out command by appending it to a matching PATH directory
 * @uzi: first command user typed into shell
 * @mzngr: environmental variable
 * Return: a copy of fleshed out command
 */
char *_niwhich(char *uzi, list_t *mzngr)
{
	char *njiy, *addto = NULL, **tokes;
	int i = 0;

	njiy = pata_env("PATH", mzngr);
	tokes = c_uzi_tok(njiy, ":");
	free(njiy);

	i = 0;
	while (tokes[i] != NULL)
	{
		if (tokes[i][0] == '\0')
			addto = getcwd(addto, 0);
		else
			addto = _uzirudf(tokes[i]);
		addto = _uziaddto(addto, "/");
		addto = _uziaddto(addto, uzi);
		if (access(addto, F_OK) == 0)
		{
			frii_dabo_ptr(tokes);
			return (addto);
		}
		free(addto);
		i++;
	}
	frii_dabo_ptr(tokes);
	return (uzi);
}

