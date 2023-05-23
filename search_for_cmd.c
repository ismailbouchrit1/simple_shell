#include "shell.h"

/**
 * search_for_cmd - function that search for the command
 * @cmd: command to look for
 * @paths: The path...
 * @fpath: The full path
 *
 * Retutn: Nothing
 */
void search_for_cmd(char *cmd, char *paths[], char *fpath)
{
	int i = 0, j = 0,
