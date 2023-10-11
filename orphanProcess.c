#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid > 0)
    {
        printf("Parent process with pid: %d \n", pid);
        printf("Subjects: \n");
        printf("1. Operating System\n");
        printf("2. Computer Networks\n");
        printf("3. Data Structures\n");
        printf("4. Database Management System\n");
        printf("5. Computer Architecture\n");
    }
    else if (pid == 0)
    {
        sleep(10);
        printf("Child process\n");
        printf("Table of 4: \n");
        for (int i = 1; i <= 10; i++)
        {
            printf("4 x %d = %d\n", i, 4 * i);
        }
    }
    else
    {
        printf("Fork failed\n");
    }

    return 0;
}