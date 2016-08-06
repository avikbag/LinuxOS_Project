#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        int pids[3], pid1, pid2, pid3, bytes, fd1[2], fd2[2], fd3[2];
        int i = 2;
        int released = 0;
        char * message = "hello world";
        char * release = "release";
        int n1 = 11;
        int n2 = 7;
        pipe(fd1);
        pipe(fd2);
        pipe(fd3);

        if ((pid1 = fork()) == 0) {
                close(fd1[1]);
                read(fd1[0], &pids, sizeof(int) * 3);
                // syscall(send, pids[1], n1, message);
                // syscall(send, pids[2], n1, message);
                while (i > 0 || released == 0) {
                        // if (syscall(receive, pids[1], n1, message) > 0) {
                                i--;
                        // }
                        // if (syscall(receive, pids[2], n1, message) > 0) {
                                i--;
                        // }
                        // if (syscall(receive, pids[1], n2, release) > 0) {
                                released = 1;
                        // }
                        // if (syscall(receive, pids[2], n2, release) > 0) {
                                released = 1;
                        // }

                }
                //syscall(send, pids[1], n2, release);
                //syscall(send, pids[2], n2, release);
                exit(0);
        }
        else if ((pid2 = fork()) == 0) {
                close(fd2[1]);
                read(fd2[0], &pids, sizeof(int) * 3);
                // syscall(send, pids[0], n1, message);
                // syscall(send, pids[2], n1, message);
                while (i > 0 || released == 0) {
                        // if (syscall(receive, pids[0], n1, message) > 0) {
                                i--;
                        // }
                        // if (syscall(receive, pids[2], n1, message) > 0) {
                                i--;
                        // }
                        // if (syscall(receive, pids[0], n2, release) > 0) {
                                released = 1;
                        // }
                        // if (syscall(receive, pids[2], n2, release) > 0) {
                                released = 1;
                        // }
                }
                //syscall(send, pids[0], n2, release);
                //syscall(send, pids[2], n2, release);
                exit(0);
        }
        else if ((pid3 = fork()) == 0) {
                close(fd3[1]);
                read(fd3[0], &pids, sizeof(int) * 3);
                // syscall(send, pids[0], n1, message);
                // syscall(send, pids[1], n1, message);
                while (i > 0 || released == 0) {
                        // if (syscall(receive, pids[0], n1, message) > 0) {
                                i--;
                        // }
                        // if (syscall(receive, pids[1], n1, message) > 0) {
                                i--;
                        // }
                        // if (syscall(receive, pids[0], n2, release) > 0) {
                                released = 1;
                        // }
                        // if (syscall(receive, pids[1], n2, release) > 0) {
                                released = 1;
                        // }

                }
                //syscall(send, pids[0], n2, release);
                //syscall(send, pids[1], n2, release);
                exit(0);
        }
        else {
                close(fd1[0]);
                close(fd2[0]);
                close(fd3[0]);

                pids[0] = pid1;
                pids[1] = pid2;
                pids[2] = pid3;

                write(fd1[1], &pids, sizeof(int) * 3);
                write(fd2[1], &pids, sizeof(int) * 3);
                write(fd3[1], &pids, sizeof(int) * 3);
        }
}
