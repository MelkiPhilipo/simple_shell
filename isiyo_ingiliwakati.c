#include "shell.h"

/**
 * c_achana - a function that ignores spaces and newlines
 * @uzi: the variables of the environment
 * Return: a new string will be returned
 */
char *c_achana(char *uzi)
{
	while (*uzi == ' ' || *uzi == '\n')
		uzi++;
	return (uzi);
}

/**
 * isiyo_ingiliwakati - handles when user pipes commands
 * @env: the variables of the environment
 */
void isiyo_ingiliwakati(list_t *env)
{
	size_t rodh = 0, h = 0;
	int amri_mstari_no = 0, kutoka_stat = 0;
	char *amri = NULL, *n_amri = NULL, **n_mstari, **tokeni;

	rodh = pata_line(&amri);
	if (rodh == 0)
	{
		free(amri);
		exit(0);
	}
	n_amri = amri;
	amri = c_achana(amri);
	n_mstari = _uzi_tok(amri, "\n");
	if (n_amri != NULL)
		free(n_amri);
	h = 0;
	while (n_mstari[h] != NULL)
	{
		amri_mstari_no++;
		tokeni = NULL;
		tokeni = _uzi_tok(n_mstari[h], " ");
		kutoka_stat = kijenzi_chandani(tokeni, env, amri_mstari_no, n_mstari);
		if (kutoka_stat)
		{
			h++;
			continue;
		}
		kutoka_stat = _kuexecve(tokeni, env, amri_mstari_no);
		h++;
	}
	frii_dabo_ptr(n_mstari);
	linked_listi_huru(env);
	exit(kutoka_stat);
}

