#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        char * message = "hello world";
        int n = 11;

        int ret = syscall(292, getpid(), n, message);
        int ret2 = syscall(293, getpid(), n, message);
        printf("%d %d\n", ret, ret2);
}
