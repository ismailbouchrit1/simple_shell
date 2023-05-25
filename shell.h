#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);


/* builtins.c */
char **tokenizer(char *line);
int handle_builtin(char **command, char *line);
void handle_signal(int m);
int checker(char **cmd, char *buf);


/* execute.c */
void execution(char *cp, char **cmd);
void exit_cmd(char **command, char *line);

/* free_fct.c */
void free_buffers(char **buf);


/*  path_handler.c  */
char *find_path(void);
char *append_path(char *path, char *command);
char *test_path(char **path, char *command);

/* print.c  */
void prompt_user(void);
int _putchar(char c);
int print_s(char *s);
void print_env(void);


/* str_handler.c  */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);


/**
 * struct builtin - singly linked list
 * @env: environment
 * @exit: exit
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * struct info - singly linked list
 * @final_exit: ----
 * @ln_count: ----
 */
struct info
{
	int final_exit;
	int ln_count;
} info;


/**
 * struct flags - singly linked list
 * @interactive: --
 */
struct flags
{
	bool interactive;
} flags;

#endif
