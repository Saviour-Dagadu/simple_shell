#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Struct containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always zero(0)
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets value of an environ variable
 * @info: Struct containing the potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *x;

	while (node)
	{
		x = starts_with(node->str, name);
		if (x && *x)
			return (x);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize new environment variable,
 *             or modify an existing one
 * @info: Struct containing the potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always zer(0)
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Struct containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always zero(0)
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates the env linked list
 * @info: Struct containing the potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always zero(0)
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
