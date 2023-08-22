#include "shell.h"
/**
 * _strdup- function to duplicate astring
 * @string : the needed to duplicate string
 *
 * Return: pointr to str dup
*/
char *_strdup(const char *string)
{
int len = 0;
char *rtn;

if (string == NULL)
{
return (NULL);
}
while (*string++)
{
len++;
}
rtn = malloc(sizeof(char) * (len + 1));
if (!rtn)
{
return (NULL);
}
for (len++; len--;)
{
rtn[len] = *--string;
}
return (rtn);
}


/**
 * _strlen - function to find string length
 * @string: string to find his length
 *
 * Return: string len
 */
int _strlen(char *string)
{
int m = 0;

if (!string)
{
return (0);
}
while (*string++)
{
m++;
}
return (m);
}

/**
 * _strcat - function to connect two strings
 * @dest: destination to store new concat str in
 * @source: buff to concat string
 *
 * Return: dest buff pointer
 */
char *_strcat(char *dest, char *source)
{
char *R = dest;

while (*dest)
{
dest++;
}
while (*source)
{
*dest++ = *source++;
}
*dest = *source;
return (R);
}

/**
 * _strcpy - string to copy
 * @d:  destination string
 * @s:  source string
 *
 * Return: ptr to dest
 */
char *_strcpy(char *d, char *s)
{
int k = 0;

if (d == s || s == 0)
{
return (d);
}
while (s[k])
{
d[k] = s[k];
k++;
}
d[k] = 0;
return (d);
}

/**
 * _strcmp - compare between 2 strings
 * @string1: strr1
 * @string2: str2
 * Return: -1 if string1 is smaller,
 * 1 if string1 is greater ,0 if equal
 */
int _strcmp(char *string1, char *string2)
{
int x;

for (x = 0; string1[x] != '\0'; x++)
;
for (x = 0; string2[x] != '\0'; x++)
{
if (string1[x] != string2[x])
{
return (string1[x] - string2[x]);
}
}
return (0);
}
