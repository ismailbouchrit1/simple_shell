#include "shell.h"

/**
 * search_for_cmd - function that search for the command
 * @cmd: command to look for
 *
 * Return: Nothing
 */
void *search_for_cmd(char *cmd)
{
	char *path, *token, *path_cmd, *cmd_path, *path_cpy;
	int path_cmd_len = 0;

	path = getenv("PATH");
	path_cpy = _strdup(path);
	token = strtok(path_cpy, ":");
	if (_strchr(cmd, '/') != NULL)
	{
		cmd_path = malloc((_strlen(cmd) + 1) * sizeof(char));
		_strcpy(cmd_path, cmd);
		return (cmd_path);
	}
	while (token)
	{
		path_cmd_len = _strlen(token) + _strlen(cmd) + 2;
		path_cmd = malloc(path_cmd_len * sizeof(char));
		_strcpy(path_cmd, token);
		_strcat(path_cmd, "/");
		_strcat(path_cmd, cmd);

		if (access(path_cmd, X_OK) == 0)
		{
			free(path_cpy);
			return (path_cmd);
		}

		token = strtok(NULL, ":");
	}
	free(path_cpy);
	free(path_cmd);
	return (NULL);
}
