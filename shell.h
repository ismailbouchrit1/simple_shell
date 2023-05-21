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

/* String handler */

int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);



#endif
