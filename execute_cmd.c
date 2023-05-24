#include "shell.h"

/**
 * execute_cmd - function to execute the command and fork
 * @args: arguments
 *
 * Return: Nothing.
 */
void execute_cmd(char **args)
{
	char *cmd_path;
	int status = 0;
	pid_t pid;

	cmd_path = search_for_cmd(args[0]);
	if (cmd_path != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Eroor fork failed:");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(cmd_path, args, environ) == -1)
			{
				perror("Error Execution failed: ");
				exit(EXIT_FAILURE);
			}
		}
		else
			waitpid(pid, &status, 0);
	}
	else
		perror("command not found :(");
}

/**
 * _free - free tokens
 * @tokens: ...
 * Return: Nothing.
 */
void _free(char **tokens)
{
	int i = 0;
	if (tokens)
	{
		for (; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
			tokens[i] = NULL;
		}
		free(tokens);
	}
}

/**
 * to_exit - handle exit
 * @args: ...
 * Return: Nothing
 */
void to_exit(char **args)
{
	int exit_ = 0;

	if (args[1] != NULL)
	{
		exit_ = atoi(args[1]);
		exit(exit_);
	}
	else
		exit(EXIT_SUCCESS);
}
