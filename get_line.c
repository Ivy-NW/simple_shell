#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Custom getline-like function using a buffer
ssize_t bespoke_getline(char **lineptr, size_t *n)
{
    static char buffer[BUFFER_SIZE];
    static size_t buffer_pos = 0;  
    static ssize_t chars_in_buffer = 0; 

    ssize_t chars_read = 0;
    ssize_t total_chars = 0;

    
    if (*lineptr == NULL || *n == 0) {
        *n = BUFFER_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1;
        }
    }

    while (1) {
        
        if (buffer_pos >= chars_in_buffer) {
            chars_in_buffer = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (chars_in_buffer <= 0) {
                break;  
            }
            buffer_pos = 0;
        }

        
        while (buffer_pos < chars_in_buffer) {
            (*lineptr)[total_chars] = buffer[buffer_pos];
            total_chars++;
            buffer_pos++;

            if (total_chars >= *n - 1) {
                
                *n *= 2;
                *lineptr = (char *)realloc(*lineptr, *n);
                if (*lineptr == NULL) {
                    return -1;  
                }
            }

            
            if ((*lineptr)[total_chars - 1] == '\n') {
                (*lineptr)[total_chars] = '\0';
                return total_chars; 
            }
        }
    }

    
    return (total_chars == 0) ? -1 : total_chars;
}

int main(void)
{
    char *line = NULL;
    size_t len = 0;

    while (1) {
        ssize_t chars_read = bespoke_getline(&line, &len);

        if (chars_read == -1) {
            if (line != NULL) {
                free(line);
            }
            break;  
        }

        printf("Read %zd characters: %s", chars_read, line);
    }

    free(line);
    return 0;
}
