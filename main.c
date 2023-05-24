#include "shell.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t size_line = 0;
	char **args;
	ssize_t n_chars = 0;

	while (1)
	{
		display_prompt();
		n_chars = _getline(&line, &size_line, stdin);

		if (n_chars == -1)
		{
			perror("Error in getline:");
			break;
		}
		args = parse_cmd(line);
		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
				to_exit(args);
			else if (_strcmp(args[0], "env") == 0)
				handle_env();
			else
				execute_cmd(args);
		}
		free(args);
	}
	return (0);
}

