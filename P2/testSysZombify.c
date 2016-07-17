#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        if (argc != 2){
                printf("Usage: sys_zombify test $PID\n");
                exit(0);
        }

        long pid = atol(argv[1]);
        if(pid){
                if(syscall(289, pid) == -1){
                        printf("PID doesn't exist!\n");
                }
        }
        else{
                printf("Usage: test_zombify $PID\n");
                exit(0);
        }
}
