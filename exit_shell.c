#include "main.h"

/**
 *ex_it - function for the exit built in command
 *(char **arr) - Specifies the parameter arr that the function takes.
 *arr - a pointer to a pointer to a character (char **). 
 */
// Prototype for the exit function
void ex_it(char **arr);

int main(void)
{
    char *user_input;  // To store user input
    size_t len;  // To store length of input

    len = 0;
    user_input = NULL;

    // Display prompt and read user input in a loop
    while (1) {
        write(STDOUT_FILENO, "$ ", 2);
        
        // Read user input
        if (getline(&user_input, &len, stdin) == -1) {
            // Handle end of input or error condition
            break;
        }

        // Tokenize user input
        char **arrayStr = _createToken(user_input);

        // Check if it's the exit command
        if (_strcmp(arrayStr[0], "exit") == 0) {
            ex_it(arrayStr);  // Call the exit built-in command function
            // At this point, the ex_it function should handle the exit
        } else {
            // Handle other commands (not exit)
            // ...
        }

        // Free memory allocated for tokenization
        free(arrayStr);
    }

    // Free memory and exit the program
    free(user_input);

    return 0;
}
