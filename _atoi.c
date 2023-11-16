#include "shell.h"

/**
 * interactive - return true if shell is in interactive mode
 * @info: structure address
 *
 * Return: One(1) if in interactive mode, zero(0) otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @y: char be to checked for
 * @delim: delimeter string
 * Return: One(1) if true, zero(0) if false
 */
int is_delim(char y, char *delim)
{
	while (*delim)
		if (*delim++ == y)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for the alphabetic character used
 * @y: character to be inputted
 * Return: One(1) if a is alphabetic, zero(0) otherwise
 */

int _isalpha(int y)
{
	if ((y >= 'a' && y <= 'z') || (y >= 'A' && y <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Convert a string to an integer.
 * @a: The string to convert.
 * Return: The converted integer. Zero if no number is in the string.
 */

int _atoi(char *a)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; a[i] != '\0' && flag != 2; i++)
	{
		if (a[i] == '-')
			sign *= -1;

		if (a[i] >= '0' && a[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (a[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
