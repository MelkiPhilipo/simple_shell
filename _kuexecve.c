#include "shell.h"

/**
 * c_kutoka - a function that makes freed of user's typed string
 * @uzi: a string typed by user
 * @mzngr: puts in the environmental linked list
 */
void c_kutoka(char **uzi, list_t *mzngr)
{
	frii_dabo_ptr(uzi);
	linked_listi_huru(mzngr);
	_exit(0);
}

/**
 * _kuexecve - a function that executes a string typed by user.
 * @z: a string typed by user
 * @mzngr: the variable of the environment
 * @hes: the user string of certain number to write error message
 * Return: Always 0 when success.
 */
int _kuexecve(char **z, list_t *mzngr, int hes)
{
	char *shika;
	int status = 0, st = 0;
	pid_t pid;

	if (access(z[0], F_OK) == 0)
	{
		shika = z[0];
		st = 1;
	}
	else
		shika = _niwhich(z[0], mzngr);
	if (access(shika, X_OK) != 0)
	{
		hai_patikani(z[0], hes, mzngr);
		frii_dabo_ptr(z);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(shika, z, NULL) == -1)
			{
				hai_patikani(z[0], hes, mzngr);
				c_kutoka(z, mzngr);
			}
		}
		else
		{
			wait(&status);
			frii_dabo_ptr(z);
			if (st == 0)
				free(shika);
		}
	}
	return (0);
}
