#include "shell.h"

/**
 * handle_env - ...
 *
 * Return: Nothing
 */
void handle_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write_the_string(1, environ[i]);
		write_the_string(1, "\n");
		i++;
	}
}
