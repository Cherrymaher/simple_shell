#include "shell.h"
/**
 * main- main function
 * @argc: arguments counter
 * @argv: commant line arguments
 * Return: 0
*/
int main(int argc, char **argv)
<<<<<<< HEAD
{	char *prmt = "$ ";
char *ext = "Exitting..\n";
=======
{
char *prmt = "$ ";
char *ext = "Exiting..\n";
>>>>>>> 2a02479388b4e00c9ae96e311c1889838b5b7255
const char *dlmtr = " \n";
char *inputptr = NULL, *inputptr_cpy = NULL, *tkn;
size_t sz = 0;
ssize_t charsno_rd;
int token_num = 0, j;

(void)argc;
while (1)
{	write(1, prmt, _strlen(prmt));
charsno_rd = getline(&inputptr, &sz, stdin);
if (charsno_rd == -1)
{	write(1, ext, _strlen(ext));	continue;
}
inputptr_cpy = malloc(sizeof(char) * (charsno_rd + 1));
if (inputptr_cpy == NULL)
{	perror("malloc failed");
	continue;
}
_strcpy(inputptr_cpy, inputptr);
tkn = strtok(inputptr, dlmtr);
while (tkn != NULL)
{	token_num++;
tkn = strtok(NULL, dlmtr);
}
token_num++;
argv = malloc(sizeof(char *) * token_num);
tkn = strtok(inputptr_cpy, dlmtr);
for (j = 0; tkn != NULL; j++)
<<<<<<< HEAD
{	argv[j] = (malloc(sizeof(char) * _strlen(tkn)));
	_strcpy(argv[j], tkn);
tkn = strtok(NULL, dlmtr);
}
argv[j] = NULL;	exec_command(argv);
for (j = 0; j < token_num; j++)
{	free(argv[j]);
continue;
=======
{
argv[j] = malloc(sizeof(char) * (_strlen(tkn) + 1));
if (argv[j] == NULL)
{
perror("malloc failed");
return (-1);
}
else
{
_strcpy(argv[j], tkn);
tkn = strtok(NULL, dlmtr);
}
}
argv[j] = NULL;
exec_command(argv);
for (j = 0; j < token_num; j++)
{
free(argv[j]);
>>>>>>> 2a02479388b4e00c9ae96e311c1889838b5b7255
}
free(argv);
free(inputptr_cpy);
<<<<<<< HEAD
free(inputptr);	return (0);
=======
}
return (0);
}
>>>>>>> 2a02479388b4e00c9ae96e311c1889838b5b7255
