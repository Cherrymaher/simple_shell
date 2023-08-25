#include "shell.h"

int main(void)
{
        int a = 6;
        int b = 4;
        int sum = a+b;
        pid_t pid;
        pid = getpid();
        
        pid_t ppid;
        ppid = getppid();
        
        printf("the sum is %d\n ", sum);

        printf("Iam the parent and my ID is %u\n", ppid);
         printf("Iam the child and my ID is %u\n", pid);
        return 0;
}
