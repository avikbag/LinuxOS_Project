#include<stdio.h>

int main() {
  int syscallnum = 285;
  printf("Process ID: %d\n", syscall(syscallnum));
  return 0;
}
