#include "shell.h"

/**
 * **strtow - splits string into words. The repeated delimiters are ignored
 * @str: input string
 * @d: delimeter string
 * Return: pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	t = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		t[j] = malloc((k + 1) * sizeof(char));
		if (!t[j])
		{
			for (k = 0; k < j; k++)
				free(t[k]);
			free(t);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			t[j][m] = str[i++];
		t[j][m] = 0;
	}
	t[j] = NULL;
	return (t);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	t = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		t[j] = malloc((k + 1) * sizeof(char));
		if (!t[j])
		{
			for (k = 0; k < j; k++)
				free(t[k]);
			free(t);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			t[j][m] = str[i++];
		t[j][m] = 0;
	}
	t[j] = NULL;
	return (t);
}
