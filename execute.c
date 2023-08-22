#include "shell.h"
/**
 * exec_command- function to execute command
 * @av: pointer to command to be executed
 * Return: exposition
 */
int exec_command(char **av)
{
pid_t pid = 0; /**Child process id*/
int position = 0, exposition = 0; /**indica status of child process*/
char *cd = NULL, *real_cd = NULL;
cd = av[0];
real_cd = _which(cd);
if (real_cd == NULL)
{
perror("command not found");
return (127);
}
pid = fork();/**create an process fork*/
if (pid == -1)/**if fork failed*/
perror("fork() error");
else if (pid == 0)/** is child */
{
av[0] = real_cd;
exposition = execve(av[0], av, environ);
if (exposition == -1)
{
exposition = 126;
perror("error");
exit(exposition);
} /**end child process and exit*/
exit(0);
}
else
wait(&position);
exposition = WEXITSTATUS(position);
return (exposition);
}
