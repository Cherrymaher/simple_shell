#include "shell.h"
/**
 * _getenv- function to get env of a global variable
 * @gb_variable : var to get its env
 *
 * Return: pointer to env or NULL if fails
*/
char *_getenv(char *gb_variable)
{
int k = 0;
const char divis[] = "=";
char *e1, *e2, *e3;

if (gb_variable != NULL)
{
if (environ == NULL)
return (NULL);
e2 = _strdup(environ[k]);
while (e2 != NULL)
{
e1 = strtok(e2, divis);
if (_strcmp(e1, gb_variable) == 0)
{
e1 = strtok(NULL, divis);
e3 = _strdup(e1);
free(e2);
return (e3);
}
k++;
free(e2);
e2 = _strdup(environ[k]);
}
}
return (NULL);
}
