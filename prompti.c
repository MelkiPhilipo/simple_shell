#include "shell.h"

/**
 * Ctrl_na_c - a function that ignores Ctrl-C input and prints prompt again
 * @h: a parameter that takes in an integer from signal
 */
void Ctrl_na_c(int h)
{
	(void)h;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * kijenzi_chandani - a function that handles builtins (exit, env, cd)
 * @tokeni: a string typed by user
 * @env: the variable of the environment
 * @hes: takes in a number of a command that user typed to write error message
 * @amri: takes in a command that will be freed
 * Return: Always 1 when acted on builtin, and 0 when not
 */
int kijenzi_chandani(char **tokeni, list_t *env, int hes, char **amri)
{
	int rodh = 0;

	if (_uzicmp(tokeni[0], "exit") == 0)
	{
		rodh = _kutoka(tokeni, env, hes, amri);
	}
	else if (_uzicmp(tokeni[0], "env") == 0)
	{
		_env(tokeni, env);
		rodh = 1;
	}
	else if (_uzicmp(tokeni[0], "cd") == 0)
	{
		rodh = _cd(tokeni, env, hes);
	}
	else if (_uzicmp(tokeni[0], "setenv") == 0)
	{
		_pangaenv(&env, tokeni);
		rodh = 1;
	}
	else if (_uzicmp(tokeni[0], "unsetenv") == 0)
	{
		_ondoapangaenv(&env, tokeni);
		rodh = 1;
	}
	return (rodh);
}

/**
 * achanana_space - a function that returns a string without spaces in front
 * @uzi: the string au uzi
 * Return: new string will be returned
 */
char *achanana_space(char *uzi)
{
	while (*uzi == ' ')
		uzi++;
	return (uzi);
}

/**
 * Ctrl_na_d - a function that exits program if Ctrl-D was pressed
 * @rodh: the characters that are read via get_line
 * @amri: the string typed by user
 * @env: the linked list of the variables of the environment
 */
void Ctrl_na_d(int rodh, char *amri, list_t *env)
{
	if (rodh == 0)
	{
		free(amri);
		linked_listi_huru(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * prompti - this function repeatedly prompts user and executes user's commands
 * @mz: the variables of the environment
 * Return: Always returns 0 on success
 */
int prompti(char **mz)
{
	list_t *env;
	size_t rodh = 0, h = 0;
	int amri_mstari_no = 0, kutoka_stat = 0;
	char *amri, *n_amri, **tokeni;

	env = env_linked_list(mz);
	do {
		amri_mstari_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			isiyo_ingiliwakati(env);
		signal(SIGINT, Ctrl_na_c);
		amri = NULL;
		rodh = 0;
		rodh = pata_line(&amri);
		Ctrl_na_d(rodh, amri, env);
		n_amri = amri;
		amri = achanana_space(amri);
		h = 0;
		while (amri[h] != '\n')
			h++;
		amri[h] = '\0';
		if (amri[0] == '\0')
		{
			free(n_amri);
			continue;
		}
		tokeni = NULL;
		tokeni = _uzi_tok(amri, " ");
		if (n_amri != NULL)
			free(n_amri);
		kutoka_stat = kijenzi_chandani(tokeni, env, amri_mstari_no, NULL);
		if (kutoka_stat)
			continue;
		kutoka_stat = _kuexecve(tokeni, env, amri_mstari_no);
	} while (1);
	return (kutoka_stat);
}

