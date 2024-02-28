#include "shell.h"

/**
 * print_orodha - a function that prints linked list
 * @k: the linked list
 * Return: ukubwa or size of linked list will be returned
 */
size_t print_orodha(list_t *k)
{
	list_t *c_orodha = k;
	int idadi = 0;
	int v = 0;

	if (k == NULL)
		return (0);
	while (c_orodha != NULL)
	{
		if (c_orodha->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			v = 0;
			while ((c_orodha->var)[v] != '\0')
				v++;
			write(STDOUT_FILENO, c_orodha->var, v);
			write(STDOUT_FILENO, "\n", 1);
		}
		c_orodha = c_orodha->inayofuata;
		idadi++;
	}
	return (idadi);
}

/**
 * ongeza_mwisho_node - a function that adds node to end of linked list
 * @kichwa: a pointer to head of the linked list
 * @uzi: the string to mpya or new node
 * Return: the pointer to the new linked list will be returned
 */
list_t *ongeza_mwisho_node(list_t **kichwa, char *uzi)
{
	list_t *mpya;
	list_t *shika;

	if (kichwa == NULL || uzi == NULL)
		return (NULL);
	mpya = malloc(sizeof(list_t));
	if (mpya == NULL)
		return (NULL);

	mpya->var = _uzirudf(uzi);
	mpya->inayofuata = NULL;

	shika = *kichwa;
	if (shika != NULL)
	{
		while (shika->inayofuata != NULL)
		{
			shika = shika->inayofuata;
		}
		shika->inayofuata = mpya;
	}
	else
	{
		*kichwa = mpya;
	}
	return (*kichwa);
}

/**
 * futa_nodeint_kwenye_faharisi - a function that removes node at index
 * @kichwa: the head address that is put in
 * @faharisi: the index that is put in
 * Return: returns 1 when success and -1 when fails
 */
int futa_nodeint_kwenye_faharisi(list_t **kichwa, int faharisi)
{
	list_t *n_kichwa;
	list_t *shika;
	int idadi = 0;

	if (*kichwa == NULL)
		return (-1);
	if (faharisi == 0)
	{
		shika = (*kichwa)->inayofuata;
		free((*kichwa)->var);
		free(*kichwa);
		*kichwa = shika;
		return (1);
	}
	idadi = 1;
	n_kichwa = *kichwa;
	while (idadi < faharisi)
	{
		if (n_kichwa == NULL)
			return (-1);
		n_kichwa = n_kichwa->inayofuata;
		idadi++;
	}
	shika = n_kichwa->inayofuata;
	n_kichwa->inayofuata = shika->inayofuata;
	free(shika->var);
	free(shika);
	return (1);
}

/**
 * linked_listi_huru - a function that frees linked list of the env var
 * @list: the linked list of the environmental variable
 */
void linked_listi_huru(list_t *list)
{
	list_t *shika;

	while (list != NULL)
	{
		shika = list;
		list = list->inayofuata;
		free(shika->var);
		free(shika);
	}

}

