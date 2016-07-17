#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

        if(argc != 2){
                printf("Usage: sys_quad $PID\n");
                exit(1);
        }

        long pid = atol(argv[1]);


        if(pid){
                long time = syscall(287, pid);
                if(time == -1){
                        printf("pid does not exist");
                }
                else{
                        printf("The new time_slice is %ld\n", time);
                }
        }
        else{
                printf("Usage: sys_quad $PID\n");
                exit(1);
        }
}
