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
