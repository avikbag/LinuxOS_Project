#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        char * message = "hello world";
        int n = 11;
        char * buffer = (char *) malloc(11 * sizeof(char));
        pid_t parentpid = getpid();
        pid_t pid1 = fork();

        if (pid1 == 0) {
            syscall(294, getpid(), n, message);
            syscall(294, parentpid, n, message);
            exit(0);
        }
        syscall(295, pid1, n, buffer);
        printf("%s\n", buffer);
}

