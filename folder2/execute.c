#include "shell.h"

/**
 * execution - executes commands entered by users
 *@cp: command
 *@cmd:vector array of pointers to commands
 * Return: 0
 */
void execution(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(cp);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buffers(cmd);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}


/**
* exit_cmd - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void exit_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
