#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        if (argc != 2){
                printf("Usage: test_myjoin $PID\n");
                exit(0);
        }

        long pid = atol(argv[1]);

        if(pid){
                printf("Returned %d\n", syscall(289, pid));
        }
        else{
                printf("Usage: test_myjoin $PID\n");
                exit(0);
        }
}