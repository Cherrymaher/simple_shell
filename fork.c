#include "shell.h"

int main(void)
{
	pid_t pid;
	pid_t ppid;
	pid_t wait(int *status);

	printf("Before fork I was alone\n");
/* fork called*/

	pid = fork();

	if (pid == -1)
	{
		perror("unsuccessful\n");

		return (1);
	}
/*parent process*/
	if (pid == 0)
	{
		printf("Iam the Dad and my ID is: %u\n", ppid);

		return (0);
	}
	else
/*child process*/
	{

		wait(NULL);
		printf("Iam the child and  my ID is:%u\n", pid);
	}
	return (0);
}
