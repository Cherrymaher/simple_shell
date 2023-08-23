#include "shell.h"
/**
 * exec_command- function to execute command
 * @av: pointer to command to be executed
 * Return: exposition
 */
int exec_command(char **av)
{
pid_t pid = 0; /** Child process id */
int position = 0, exposition = 0; /** Indicates status of child process */
char *cd = NULL, *real_cd = NULL;
cd = av[0];
real_cd = _which(cd);
if (real_cd == NULL)
{
perror("command not found");
return (127);
}
pid = fork(); /** Create a child process */
if (pid == -1) /** If fork failed */
{
perror("fork() error");
return (1);
}
else if (pid == 0) /** Child process */
{
av[0] = real_cd;
exposition = execve(av[0], av, environ);
perror("execve error");
exit(exposition);
}
else /** Parent process */
{
if (wait(&position) == -1)
{
perror("wait error");
return (1);
}
if (WIFEXITED(position))
exposition = WEXITSTATUS(position);
else
exposition = 1; /** Non-zero exit status */
}
return (exposition);
}
