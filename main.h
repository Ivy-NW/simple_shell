#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stddef.h>
extern char **environ;
/**
 *struct builtins_s - a struct that points to the string in
 *an array a struct
 *@command: a variable that points to the string in my array of
 *structs
 *@ptr: a variable that is a function pointer that takes in a char **
 *as an argument
 */
typedef struct builtins_s{
	char *command;
	void (*ptr)(char **);
}builtins_f;
char *_getenv(const char *name);
char *_strdup(char *str);
char **_createToken(char *user_input);
char *_strstr(char *haystack, char *needle);
int checking_built(char **arr);
void ex_it(char **arr);
int checking_built(char **arr);
void _createChild_P(char **arrayStr, char **_getPATH_res);
char **_getPATH(char *str, char **tok_UsInput);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void environment(char **arr);
char *_memset(char *s, char b, unsigned int n);
void _createChild(char **arrayStr);
#endif
