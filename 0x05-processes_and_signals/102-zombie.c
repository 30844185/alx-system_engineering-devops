#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

int main(void)
{
    pid_t zombie_child;
    int j;

    for (j = 0; j < 5; j++)
    {
        zombie_child = fork();
        if (zombie_child == 0)
        {
            printf("Zombie process created, PID: %d\n", getpid());
            return (infinite_while());
        }
    }
    return (0);
}
