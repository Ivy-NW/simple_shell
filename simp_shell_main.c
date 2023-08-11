#include "main.h"
/**
 *main - a function that prompts the user for input to run shell commands
 *Return: The function will return 0 on success
 */
int main(void)
{
	char *user_input, **arrayStr, *env_result, **_getPATH_res;
	size_t len; int i, a;

	len = i = a = 0; user_input = NULL;
	arrayStr = malloc(sizeof(char *) * 800);
	if (arrayStr == NULL)
		exit(1);
	write(STDOUT_FILENO, "$ ", 2);
	while (getline(&user_input, &len, stdin) != -1)
	{
		if (user_input[0] != '\n' && user_input[0] != '#')
		{
			arrayStr = _createToken(user_input);
			if (checking_built(arrayStr) == 1)
			{
				if (_strstr(arrayStr[0], "/") != NULL)
				{
					_createChild(arrayStr);
					write(STDOUT_FILENO, "$ ", 2);
				}
				else
				{
					env_result = _getenv("PATH");
					_getPATH_res =
						_getPATH(env_result, arrayStr);
					_createChild_P(arrayStr, _getPATH_res);
					write(STDOUT_FILENO, "$ ", 2);
				}
			}
			else
				write(STDOUT_FILENO, "$ ", 2);
			free(arrayStr);
		}
		else
			write(STDOUT_FILENO, "$ ", 2);
	}
	return (0);
}
