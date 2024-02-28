#include "shell.h"

/**
 * _ku_atoyi - this function changes string into an interger
 * @ng: this parameter is the string
 * Return: If success it returns number, and if string lacks numbers returns -1
 */
int _ku_atoyi(char *ng)
{
	int rodh = 0;
	unsigned int hes = 0;

	while (ng[rodh] != '\0')
	{
		if (ng[rodh] >= '0' && ng[rodh] <= '9')
			hes = hes * 10 + (ng[rodh] - '0');
		if (ng[rodh] > '9' || ng[rodh] < '0')
			return (-1);
		rodh++;
	}
	return (hes);
}

/**
 * _kutoka - a function that frees a user input and exit with main program
 * @uzi: what the user puts on a shell
 * @env: it search for environment variable and freed when error
 * @hes: it counts and print error message
 * @amri: puts in command and then freed
 * Return: Always 0 when success and returns 2 when fails
 */
int _kutoka(char **uzi, list_t *env, int hes, char **amri)
{
	int thamani = 0;

	if (uzi[1] != NULL)
		thamani = _ku_atoyi(uzi[1]);

	if (thamani == -1)
	{
		namba_isiyohalali(uzi[1], hes, env);
		frii_dabo_ptr(uzi);
		return (2);
	}
	frii_dabo_ptr(uzi);
	linked_listi_huru(env);
	if (amri != NULL)
		frii_dabo_ptr(amri);
	exit(thamani);
}
