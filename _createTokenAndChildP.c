#include "main.h"
/**
 *_createToken - a function that mallocs space to create tokens
 *@user_input: Takes the input from users
 *Return: The newly malloc'd space
 */
char **_createToken(char *user_input)
{
	char **commands;
	int i;

	commands = malloc(sizeof(char *) * 800);
	if (commands == NULL)
		_exit(1);
	i = 0;
	commands[i] = strtok(user_input, "\n ");
	while (commands[i] != NULL)
	{
		i++;
		commands[i] = strtok(NULL, "\n ");
	}
	return (commands);
}
/**
 *_createChild_P - a function that creates a child process and executes
 *each directory found in the PATH with each user input appended at the end
 *@arrayStr: A variable that takes in the tokenized string
 *@_getPATH_res: A variable that takes in the PATH that's been split up
 *into individual directories
 */
void _createChild_P(char **arrayStr, char **_getPATH_res)
{
	pid_t child_p;
	int waiting, i;

	i = 0;
	child_p = fork();
	if (child_p == -1)
	{
		perror("Error: Child process not created");
		free(arrayStr);
		free(_getPATH_res);
		_exit(1);
	}
	if (child_p == 0)
	{
		i = 0;
		while (_getPATH_res[i] != NULL)
			if (execve(_getPATH_res[i], arrayStr, NULL) == -1)
				i++;
		write(STDERR_FILENO,
		      "This command does not exist.", 28);
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		wait(&waiting);
}
/**
 *_createChild - a function that executes the user input that begin with "/"
 *@arrayStr: a variable that holds the user input
 */
void _createChild(char **arrayStr)
{
	pid_t child_p;
	int waiting, execve_check;

	child_p = fork();
	if (child_p == -1)
	{
		perror("Error: Child process not created");
		free(arrayStr);
		_exit(1);
	}
	if (child_p == 0)
	{
		execve_check = execve(arrayStr[0], arrayStr, environ);
		if (execve_check == -1)
		{
			perror("This command does not exist.");
			write(STDOUT_FILENO, "\n", 1);
			free(arrayStr);
			_exit(1);
		}
	}
	else
		wait(&waiting);
}
