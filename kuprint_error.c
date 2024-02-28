#include "shell.h"

/**
 * hai_patikani - a function that writes error
 * @uzi: a command typed by user
 * @v_h: the number of the command typed by user
 * @env: takes in linked list of envirnmental variables to write shell name
 */
void hai_patikani(char *uzi, int v_h, list_t *env)
{
	int idadi = 0;
	char *shelli, *hes;

	shelli = pata_env("_", env);
	while (shelli[idadi] != '\0')
		idadi++;
	write(STDOUT_FILENO, shelli, idadi);
	free(shelli);
	write(STDOUT_FILENO, ": ", 2);
	hes = integer_kwenda_string(v_h);
	idadi = 0;
	while (hes[idadi] != '\0')
		idadi++;
	write(STDOUT_FILENO, hes, idadi);
	free(hes);
	write(STDOUT_FILENO, ": ", 2);
	idadi = 0;
	while (uzi[idadi] != '\0')
		idadi++;
	write(STDOUT_FILENO, uzi, idadi);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * haiwezi_kucd_kwenye - a function that  writes error eg can't cd to
 * @uzi: the argument typed by user after the command cd
 * @v_h: the number or position of the command typed by user
 * @env: takes in linked list of envirnmental variables to write shell name
 */
void haiwezi_kucd_kwenye(char *uzi, int v_h, list_t *env)
{
	int idadi = 0;
	char *shelli, *hes;

	shelli = pata_env("_", env);
	while (shelli[idadi] != '\0')
		idadi++;
	write(STDOUT_FILENO, shelli, idadi);
	free(shelli);
	write(STDOUT_FILENO, ": ", 2);
	hes = integer_kwenda_string(v_h);
	idadi = 0;
	while (hes[idadi] != '\0')
		idadi++;
	write(STDOUT_FILENO, hes, idadi);
	free(hes);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	idadi = 0;
	while (uzi[idadi] != '\0')
		idadi++;
	write(STDOUT_FILENO, uzi, idadi);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * namba_isiyohalali - a function that writes error eg Illegal number
 * @uzi: the argument typed by user after the command exit
 * @v_h: the position of the command typed by user
 * @env: takes in linked list of envirnmental variables to write shell name
 */
void namba_isiyohalali(char *uzi, int v_h, list_t *env)
{
	int idadi = 0;
	char *shelli = NULL, *hes = NULL;

	shelli = pata_env("_", env);
	while (shelli[idadi] != '\0')
		idadi++;
	write(STDOUT_FILENO, shelli, idadi);
	free(shelli);
	write(STDOUT_FILENO, ": ", 2);
	hes = integer_kwenda_string(v_h);
	idadi = 0;
	while (hes[idadi] != '\0')
		idadi++;
	write(STDOUT_FILENO, hes, idadi);
	free(hes);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	idadi = 0;
	while (uzi[idadi] != '\0')
		idadi++;
	write(STDOUT_FILENO, uzi, idadi);
	write(STDOUT_FILENO, "\n", 1);
}
