#include "shell.h"
/**
 * _which - function to find the path
 * @cmd : command to find its path
 * Return: null
*/
char *_which(char *cmd)
{
char *path1, *path2, *p_token, *all_path;
int d_size, c_size;
struct stat buff;
path1 = _getenv("PATH");
if (path1)
{
path2 = strdup(path1);
c_size = strlen(cmd);
p_token = strtok(path2, ":");
while (p_token != NULL)
{
d_size = strlen(p_token);
all_path = malloc(c_size + d_size + 2);
if (all_path == NULL)
{
perror("malloc error");
free(path2);
return (NULL);
}
strcpy(all_path, p_token);
strcat(all_path, "/");
strcat(all_path, cmd);
if (stat(all_path, &buff) == 0)
{
free(path2);
return (all_path);
}
else
{
free(all_path);
p_token = strtok(NULL, ":");
}
}
free(path2);
if (stat(cmd, &buff) == 0)
{
return (cmd);
}
}
return (NULL);
}
