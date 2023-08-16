#include "main.h"

/**
 *_strdup - A function that takes in the string as a parameter
 *@str: A pointer that points the memory address
 *that holds the string
 *Return: A pointer to a duplicated string or returns NULL if
 *there was insufficient memory.
 */

char *_strdup(char *str)
{
	unsigned int a, i;
	char *p;

	if (str == NULL)
	{
		return (NULL);
	}
	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	a++;
	p = malloc((a) * sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/**
 *_strcat - A function that concatenates two strings.
 *@dest: a variable that holds the string that will be appended to src.
 *@src: a variable that holds a string that will be appended to.
 *Return: The wole string is returned.
 */

char *_strcat(char *dest, char *src)
{
	int i, a;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	a = 0;
	while (src[a] != '\0')
	{
		dest[i] = src[a];
		i++;
		a++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 *_strcpy - Function that copies the string pointed to by src, including the
 *terminating null byte, to the buffer pointed to by dest
 *@src: variable that holds the string.
 *@dest: variable receiving the string.
 *Return: The string is returned.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != 0; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);
}

/**
 *_strstr - finds the first occurence of the substring needle in the string
 *haystack.
 *@haystack: A variable containing the final output
 *@needle: A variable that is affecting haystack.
 *Return: The null if the word is not there.
 */

char *_strstr(char *haystack, char *needle)
{
	int i, i2, b;

	i = 0;
	while (haystack[i] != '\0')
	{
		b = i;
		i2 = 0;
		while (needle[i2] != '\0' && needle[i2] == haystack[i]
		       && haystack[i] != '\0')
		{
			i++;
			i2++;
		}
		if (needle[i2] == '\0')
		{
			return (haystack + b);
		}
		i = b + 1;
	}
	return (0);
}

/**
 *_memset - a function that fills memory with a constant byte.
 *@s: a pointer that points to the memory area
 *@b: a constant byte
 *@n: a fixed number of bytes
 *Return: returns new output
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int m = 0;

	while (m < n)
	{
		s[m] = b;
		m++;
	}
	return (s);
}
