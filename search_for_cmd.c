#include "shell.h"

/**
 * search_for_cmd - function that search for the command
 * @cmd: command to look for
 * @paths: The path...
 * @fpath: The full path
 *
 * Retutn: Nothing
 */
void *search_for_cmd(char *cmd)
{
	char *path, *token, *path_cmd, *cmd_path;
	int path_cmd_len = 0;

	path = getenv("PATH");
	token = strtok(path, ":");
	if (_strchr(cmd, '/') != NULL)
	{
		cmd_path = malloc((_strlen(cmd) + 1) * sizeof(char));
		_strcpy(cmd_path, cmd);
		return (cmd_path);
	}
	while (token != NULL)
	{
		path_cmd_len = _strlen(token) + _strlen(cmd) + 2;
		path_cmd = malloc(path_cmd_len * sizeof(char));
		_strcpy(path_cmd, token);
		_strcat(path_cmd, "/");
		_strcat(path_cmd, cmd);

		if (access(path_cmd, X_OK) == 0)
			return (path_cmd);

		free(path_cmd);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
