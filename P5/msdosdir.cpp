#include <fcntl.h>
#include <iostream>
#include <unistd.h>

#include "byte.h"
#include "DirectoryEntry.h"
#include "BootStrapSector.h"

using namespace std;

int main(int argc, char *argv[]){

	int fileImage;

	BootStrapSector *b;
	DirectoryEntry *d;

	if(argv != 2){
		printf("Usage: %s FILE\n", argv[0]);
		return -1;
	}
	
	fileImage = open(argv[1], O_RDONLY);

	if(fileImage == -1){
		printf("Error opening image file %s\n", argv[1]);
		return -1;
	}


		
}
