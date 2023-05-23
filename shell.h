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

#define BUFSIZE 1024


/* String handler */

int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

/* Tokenize_string */
void tokenize(char *str, char *delim, char *token[]);


/* _getline  */
void _bringline(char **line, size_t *n, char *buffer, size_t i);
ssize_t _getline(char **line, size_t *n, FILE *stream);


#endif
