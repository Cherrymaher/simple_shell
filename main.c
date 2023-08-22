#include "shell.h"
/**
 * main- main function
 * @argc: arguments counter
 * @argv: commant line arguments
 * Return: 0
*/
int main(int argc, char **argv)
{
char *prmt = "$ ";
char *ext = "Exitting..\n";
const char *dlmtr = " \n";
char *inputptr = NULL, *inputptr_cpy = NULL, *tkn;
size_t sz = 0;
ssize_t charsno_rd;
int token_num = 0, j;
(void)argc;
while (1)
{
write(1, prmt, _strlen(prmt));
charsno_rd = getline(&inputptr, &sz, stdin);
if (charsno_rd == -1)
{
write(1, ext, _strlen(ext));
continue;
}
inputptr_cpy = (malloc(sizeof(char) * charsno_rd));
if (inputptr_cpy == NULL)
{
perror("malloc failed");
continue;
}
_strcpy(inputptr_cpy, inputptr);
tkn = strtok(inputptr, dlmtr);
while (tkn != NULL)
{
token_num++;
tkn = strtok(NULL, dlmtr);
}
token_num++;
argv = malloc(sizeof(char *) * token_num);
tkn = strtok(inputptr_cpy, dlmtr);
for (j = 0; tkn != NULL; j++)
{
argv[j] = (malloc(sizeof(char) * _strlen(tkn)));
_strcpy(argv[j], tkn);
tkn = strtok(NULL, dlmtr);
}
argv[j] = NULL;
exec_command(argv);
for (j = 0; j < token_num; j++)
{
free(argv[j]);
continue;
}
free(argv);
continue;
}
free(inputptr_cpy);
free(inputptr);
return (0);
}
