#include "main.h"

/**
 *environment - pointer for the 'env' built in command
 *
 */
// Prototype for the environment function
void environment(char **arr);

int main(void)
{
    char *user_input;
    size_t len;

    len = 0;
    user_input = NULL;

    while (1) {
        write(STDOUT_FILENO, "$ ", 2);

        // Read user input
        if (getline(&user_input, &len, stdin) == -1) {
            // Handle end of input or error condition
            break;
        }

        // Tokenize user input
        char **arrayStr = _createToken(user_input);

        // Check for built-in commands
        if (_strcmp(arrayStr[0], "env") == 0) {
            environment(arrayStr);  // Call the environment built-in command function
        } else {
            // Handle other commands (not env)
            // ...
        }

        // Free memory allocated for tokenization
        free(arrayStr);
    }

    // Free memory and exit the program
    free(user_input);

    return 0;
}

// Implementation of the environment built-in function
void environment(char **arr)
{
    int i;

    // Check for additional arguments
    if (arr[1] != NULL) {
        write(STDOUT_FILENO, "env: too many arguments\n", 24);
        return;
    }

    // Iterate through environment variables and print them
    for (i = 0; environ[i] != NULL; i++) {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
}
