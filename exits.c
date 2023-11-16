#include "shell.h"

/**
 * _strncpy - Copies a specified number of char from one string to another.
 * @dest: Destination string to be copied to.
 * @src: Source string.
 * @n: Amount of characters to be copied.
 *
 * Return: A pointer to the concatenated string 'dest'.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *a = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (a);
}

/**
 **_strncat - concatenates the two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *a = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (a);
}

/**
 * _strchr - Locates a character in a string.
 * @a: The string to be parsed.
 * @y: The character to look for.
 *
 * Return: pointer to memory area of 'a' where 'y' is found,
 * or NULL if 'y' is not found.
 */
char *_strchr(char *a, char y)
{
	do {
		if (*a == y)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}
