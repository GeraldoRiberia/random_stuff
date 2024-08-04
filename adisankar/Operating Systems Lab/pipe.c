#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd[3], pid;
    char *msg = "os lab \n";
    char buf[30];

    pipe(fd);
    pid = fork();

    if (pid == 0) {
        puts("child process");
        close(fd[0]);
        write(fd[1], msg, 30);
    } else {
        sleep(1);
        puts("Parent process");
        close(fd[1]);
        read(fd[0], buf, 30);
        printf("%s", buf);
    }
    
    return 0;
}