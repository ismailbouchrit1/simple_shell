#include"shell.h"

/**
 * _putchar - write char
 * @c: char to print
 * Return: 1 (Success), -1 (Fail)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print string
 * @str: string printed
 * Return: void
 */

void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _strdup - duplicate a string
 * @str: string to duplicate
 * Return: pointer to duplicated string
 */

char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
	return (NULL);

	while (*str++)
	len++;

	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);

	for (len++; len--;)
		ret[len] = *--str;

	return (ret);
}

/**
 * _strchr - locate a character in a string
 *
 * @s: pointer to string
 * @c: character
 *
 * Return: pointer to first occurrence of @c in @s
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	if (s[i] == c)
		return (s + i);
	return (NULL);
}
