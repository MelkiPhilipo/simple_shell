#include "shell.h"

/**
 * env_linked_list - a function that creates a linked list from env variables
 * @env: the variables of the environment
 * Return: the linked list will be returned
 */
list_t *env_linked_list(char **env)
{
	list_t *kichwa;
	int rodh = 0;

	kichwa = NULL;
	while (env[rodh] != NULL)
	{
		ongeza_mwisho_node(&kichwa, env[rodh]);
		rodh++;
	}
	return (kichwa);
}

/**
 * _env - a function that prints env variables
 * @uzi: a command typed by user into shell
 * @env: the variables of the environment
 * Return: Always returns 0 on success
 */
int _env(char **uzi, list_t *env)
{
	frii_dabo_ptr(uzi);
	print_orodha(env);
	return (0);
}

