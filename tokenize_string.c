#include "shell.h"
/**
 * tokenize - fuction to split a string into tokens
 * @str: string to be tokenized
 * @delim: the delimiter
 * @token: The tokens
 * Return: Nothing
 */
void tokenize(char *str, char *delim, char *token[])
{
	int i = 0, len = 0, delim_len = 0, start_token = 0;
	int same = 1, j = 0, k = 0;

	len = _strlen(str);
	delim_len = _strlen(delim);
	for (; j < len; j++)
	{
		for (; k < delim_len; k++)
		{
			if (str[j + k] != delim[k])
			{
				same = 0;
				break;
			}
		}
		if (same)
		{
			token[i] = malloc(j - start_token + 1);
			_strncpy(token[i], str + start_token,
					j - start_token);
			token[i][j - start_token] = '\0';
			start_token = j + delim_len;
			i++;
		}
	}
	if (start_token < len && i)
	{
		token[i] = malloc(len - start_token + 1);
		_strncpy(token[i], str + start_token, len - start_token);
		token[i][len - start_token] = '\0';
		i++;
	}
	token[i] = NULL;
}

