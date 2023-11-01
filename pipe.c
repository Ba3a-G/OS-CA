// Create a C program that creates a pipe, forks a child process, and uses the pipe to communicate between the parent and child processes. The parent process should send a message to the child process, and the child process should print the message to standard output. The child process should then send a message back to the parent process, and the parent process should print the message to standard output.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (pid == 0) {
        // child process
        char buffer[6];
        read(fd[0], buffer, 6);
        printf("Child process received message: %s\n", buffer);
        close(fd[0]);
    } else {
        // parent process
        char buffer[] = "Hello";
        write(fd[1], buffer, 6);
        close(fd[1]);
    }
    return 0;
}