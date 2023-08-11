#include "main.h"
/**
 *checking_built - a function that checks if the user typed a builtin
 *@arr: a variable that takes in the user input
 *Return: 0 on success and 1 on failure
 */
int checking_built(char **arr)
{
	int i, j, len_input;
	builtins_f check[] = {
		{"exit", ex_it},
		{"env", environment},
		{NULL, NULL}
	};

	i = j = 0;
	for (len_input = 0; arr[0][len_input] != '\0'; len_input++)
		;
	while (check[i].command != NULL)
	{
		j = 0;
		while (j < len_input)
		{
			if (check[i].command[j] != arr[0][j])
				break;
			j++;
		}
		if (check[i].command[j] == arr[0][j])
		{
			check[i].ptr(arr);
			return (0);
		}
		i++;
	}
	return (1);
}
/**
 *ex_it - a builtin function that frees the tokenized user input
 *@arr: the variable that holds the tokenized user input
 */
void ex_it(char **arr)
{
	free(arr);
	write(STDOUT_FILENO, "Exiting the process\n", 21);
	_exit(0);
}
/**
 *environment - a builtin funtion that gets the
 *environment of the user's computer
 *@arr: a variable that takes in the userinput
 */
void environment(char **arr)
{
	int i, len;

	len = 0;
	if (arr[1] == NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			for (len = 0; environ[i][len] != '\0'; len++)
				;
			write(STDOUT_FILENO, environ[i], len);
			write(STDOUT_FILENO, "\n", 2);
		}
	}
	else
	{
		write(STDOUT_FILENO, "env does not have any flags or arguments", 40);
		write(STDOUT_FILENO, "\n", 2);
	}
}
