#include <fcntl.h>
#include <iostream>
#include <unistd.h>

#include "byte.h"
#include "DirectoryEntry.h"
#include "BootStrapSector.h"
#include "DirectoryListing.h"

using namespace std;

int main(int argc, char *argv[]){

	BootStrapSector *b = NULL;
	DirectoryListing *d = NULL;
	DirectoryEntry *e = NULL;

	byte* serialNumber;
	string volLabel;

	int totalFiles = 0; //init num of files
	int totalSize = 0;

	if(argc != 2){
		printf("Usage: %s FILE\n", argv[0]);
		return -1;
	}
	
	b = new BootStrapSector(argv[1]);
	d = new DirectoryListing(argv[1]);
	// serialNumber = b->getVolumeSerialNumber();
	// cout << "Volume Serial Number is " << serialNumber << endl;
	DirectoryEntry *temp = new DirectoryEntry(d->getEntry(d->getSize() - 1));	
	volLabel = temp->getFileName() + temp->getFileExt();
	cout << "Volume name is " << volLabel << endl;

	for(int i = 0; i < d->getSize() - 1; i ++){
		e = new DirectoryEntry(d->getEntry(i));
		e->print();
		totalFiles++;
		totalSize += e->getFileSize();
	}
	
	cout << totalFiles << " file(s) " << totalSize << " bytes" << endl;

}
