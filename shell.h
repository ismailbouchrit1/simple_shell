#ifndef SHELL_H
#define SHELL_H

/*include header lib*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#define TOKEN_DELIM " \n\t"
#define BUFFER_SIZE 1024

extern char **environ;

/* String handler */

int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char c);

/*parse the command*/
char **parse_cmd(char *line);

/*search and execute command*/
void *search_for_cmd(char *cmd);
void execute_cmd(char **args);
void to_exit(char **args);
void _free(char **tokens);

/* print environement and getenv functions*/
void handle_env(void);

/*prompt function*/
void write_the_string(int fd, const char *str);
void display_prompt(void);

/*converter*/
int _atoi(char *str);
#endif
