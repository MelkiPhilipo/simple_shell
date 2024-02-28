#include "shell.h"

/**
 * mzngr_linked_list - a function that creates a linked list from env variables
 * @mzngr: the variables of the environment
 * Return: the linked list will be returned
 */
list_t *mzngr_linked_list(char **mzngr)
{
	list_t *kichwa;
	int rodh = 0;

	kichwa = NULL;
	while (mzngr[rodh] != NULL)
	{
		ongeza_mwisho_node(&kichwa, mzngr[rodh]);
		rodh++;
	}
	return (kichwa);
}

/**
 * _mzngr - a function that prints env variables
 * @uzi: a command typed by user into shell
 * @mzngr: the variables of the environment
 * Return: Always returns 0 on success
 */
int _mzngr(char **uzi, list_t *mzngr)
{
	frii_dabo_ptr(uzi);
	print_orodha(mzngr);
	return (0);
}

