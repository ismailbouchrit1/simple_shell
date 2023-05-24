#include "shell.h"

/**
 * parse_command - ...
 * @line: ...
 *
 * Return: ...
 */
char **parse_cmd(char *line)
{
	int buffer_size = 0, pos = 0;
	char **tokens;
	char *token;

	buffer_size = BUFFER_SIZE;
	tokens = malloc(buffer_size * sizeof(char *));
	if (!tokens)
	{
		write_the_string(1, "Error to allocat memory\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOKEN_DELIM);

	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= buffer_size)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[pos] = NULL;
	return (tokens);
}
