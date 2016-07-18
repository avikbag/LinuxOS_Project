#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
	if (argc != 2){
		printf("Usage: forcewrite $target_file\n");
	}
	
	char * fileName = argv[1];
	int fd = open(fileName, O_RDONLY);
	int normalRet = write(fd, "Normal write", 12);
	if (normalRet == -1){
		printf("Normal write failed.\n");
	} else {
		printf("Normal write succeeded; are you sure the file is read only?\n"); 
	}	
	int ret = syscall(291, fd, "Forcewrite", 10); 
	if (ret > -1) {
		printf("Forcewrite successful! Check target file\n");
	} else {
		printf("Forcewrite failed.. something went wrong.\n");
	}
	return ret;
}
