#include "shell.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer = NULL, *cmd, **args
	size_t line_size = 0;
	pid_t pid;
	int status, i = 0;

	while (1)
	{
		write(1, "$ ", 2);
		getline(&buffer, &line_size, stdin);
		if ((pid = fork() == -1)
		{
			perror("Error:fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			cmd = strtok(buffer, " \n");
			args = malloc(sizeof (char*) * 1024);
			for (; cmd != NULL; i++)
			{
				args[i] = cmd;
				cmd = strtok(NULL, " \n");
			}
			args[i] = NULL;
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error in execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("Error in wait:");
				exit(EXIT_FAILURE);
			}
		}
	}
	free(buffer);
	return (0);
}
