#include "shell.h"

/**
 * write_the_string - ..
 * @fd: ..
 * @str: ...
 * Return: Nothing.
 */
void write_the_string(int fd, const char *str)
{
	size_t len = 0;
	ssize_t w_bytes;

	if (isatty(STDIN_FILENO) == 1)
	{
		len = _strlen(str);
		w_bytes = write(fd, str, len);
		if (w_bytes == -1)
			exit(EXIT_FAILURE);
	}
}

/**
 * display_prompt - ...
 *
 * Return: Nothing.
 */
void display_prompt(void)
{
	write_the_string(1, "$ ");
}
