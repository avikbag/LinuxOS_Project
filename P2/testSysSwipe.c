#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        long swiped;

        if(argc != 3){
                printf("Usage: sys_swipe $target $victim\n");
                exit(1);
        }

        long target = atol(argv[1]);
        long victim = atol(argv[2]);


        swiped = syscall(288, target, victim);
        if(swiped == -1){
                printf("Error swiping time\n");
        }
        else {
                printf("The process %lu now has a time_slice of %lu\n", target, swiped);
        }
}
