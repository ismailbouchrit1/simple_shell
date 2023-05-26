#include "shell.h"

/**
 * _bringline - assigns the line var for _getline
 * @line: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @i: size of buffer
 */
void _bringline(char **line, size_t *n, char *buffer, size_t i)
{

	if (*line == NULL)
	{
		if  (i > BUFFER_SIZE)
			*n = i;
		else
			*n = BUFFER_SIZE;
		*line = buffer;
	}
	else if (*n < i)
	{
		if (i > BUFFER_SIZE)
			*n = i;
		else
			*n = BUFFER_SIZE;
		*line = buffer;
	}
	else
	{
		_strcpy(*line, buffer);
		free(buffer);
	}
}
/**
 * _getline - Read inpt from stream
 * @line: buffer that stores the input
 * @n: size of line
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFFER_SIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	_bringline(line, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
