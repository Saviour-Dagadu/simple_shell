#include "shell.h"

/**
 * _myhistory - displays history list, 1 command by line, preceded
 *              with line numbers, starting at zero.
 * @info: Struct containing the potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always zero(0).
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter structure
 * @str: string alias
 *
 * Return: Always zero(0) on success, one(1) on error
 */
int unset_alias(info_t *info, char *str)
{
	char *x, y;
	int ret;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	y = *x;
	*x = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*x = y;
	return (ret);
}

/**
 * set_alias - Set the alias to a given string.
 * @info: Parameter structure.
 * @str: String alias.
 *
 * Return: Always zero (0) on success, one (1) on error.
 */
int set_alias(info_t *info, char *str)
{
	char *x;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - print the alias string
 * @node: alias node
 *
 * Return: Always zero(0) on success, one(1) on error
 */
int print_alias(list_t *node)
{
	char *x = NULL, *a = NULL;

	if (node)
	{
		x = _strchr(node->str, '=');
		for (a = node->str; a <= x; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(x + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics alias builtin (man alias)
 * @info: Struct containing the potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always zero(0)
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *x = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		x = _strchr(info->argv[i], '=');
		if (x)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
