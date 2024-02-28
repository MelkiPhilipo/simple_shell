#include "shell.h"

/**
 * main - a function that creates a simple shell
 * @arc: argument count
 * @argv: argument vectors
 * @mz: environmental variables
 * Return: Always 0 on success
 */
int main(int arc, char **argv, char **mz)
{
	(void)arc;
	(void)argv;

	prompti(mz);

	return (0);
}

