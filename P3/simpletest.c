#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        char * message = "hello world";
        int n = 11;
        char * buffer = (char *) malloc(11 * sizeof(char));
        int ret = syscall(292, getpid(), n, message);
        int ret2 = syscall(293, getpid(), n, buffer);
        printf("%d %d\n", ret, ret2);
        printf("%s\n", buffer);
}
