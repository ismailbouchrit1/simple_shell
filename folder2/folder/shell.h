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


/*  memHandler.c  */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void memcopy(void *newptr, const void *ptr, unsigned int size);

/* Tokenize_string */
void tokenize(char *str, char *delim, char *token[]);


/* _getline  */
void _bringline(char **line, size_t *n, char *buffer, size_t i);
ssize_t _getline(char **line, size_t *n, FILE *stream);


/*converter*/
int _atoi(char *str);

/*getline funtion*/
void _bringline(char **line, size_t *n, char *buffer, size_t i);
ssize_t _getline(char **line, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void memcopy(void *newptr, const void *ptr, unsigned int size);

#endif
