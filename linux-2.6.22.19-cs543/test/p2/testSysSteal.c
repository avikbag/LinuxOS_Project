#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        if (argc != 2){
                printf("Usage: test_steal $PID\n");
                exit(0);
        }

        long pid = atol(argv[1]);

        if(pid){
                if(syscall(286, pid) == -1){
                        printf("pid doesn't exist!\n");
                }
        }
        else{
                printf("Usage: test_steal $PID\n");
                exit(0);
        }
}
