#include "shell.h"

/**
 * pata_line - a function that receives string from a user and stores
 * @uzi: folder
 * Return: The characters number that read
 */
size_t pata_line(char **uzi)
{
	ssize_t rodh = 0, ukubwa = 0, st = 0, st2 = 0, h = 0;
	char folder[1024];

	while (st2 == 0 && (rodh = read(STDIN_FILENO, folder, 1024 - 1)))
	{
		if (rodh == -1)
			return (-1);

		folder[rodh] = '\0';

		h = 0;
		while (folder[h] != '\0')
		{
			if (folder[h] == '\n')
				st2 = 1;
			h++;
		}

		if (st == 0)
		{
			rodh++;
			*uzi = malloc(sizeof(char) * rodh);
			*uzi = _uzikopi(*uzi, folder);
			ukubwa = rodh;
			st = 1;
		}
		else
		{
			ukubwa += rodh;
			*uzi = _uziaddto(*uzi, folder);
		}
	}
	return (ukubwa);
}

