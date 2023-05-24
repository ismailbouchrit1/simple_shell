#include "shell.h"

/**
 * _strlen - return len of string
 * @s: the string counted
 * Return: len of string
 */

int _strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - compare two strings
 * @s1: 1st string
 * @s2: 2nd string
 * Return: 0 if (s1 = 2), 1 if (s1 > s2), -1 if (s1 < s2)
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
	if (*s1 != *s2)
		return (*s1 - *s2);

	s1++;
	s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strcat - concat twi string
 * @dest: destination buffer
 * @src: source buffer
 * Return: pointer to desti buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;

	*dest = *src;
	return (ret);
}

/**
 * _strcpy - copy a string
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
 * _strncpy - copies a string
 * @dest: destination of value
 * @src: source of value
 * @n: number of character to copy
 * Return: A pointer to the resulting of string destination
 */
char *_strncpy(char *dest, char *src, int n)
{
	int k = 0, j = 0;

	while (src[k])
	{
		k++;
	}
	while (j < n && src[j])
	{
		dest[j] = src[j];
		j++;
	}

	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}
