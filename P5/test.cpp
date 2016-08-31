#include "byte.h"
#include "DirectoryEntry.h"
#include "BootStrapSector.h"
#include <iostream>
#include <fcntl.h>


using namespace std;

int main(int argc, char *argv[]){
	BootStrapSector b("samplefat.bin");
	DirectoryEntry **d = NULL;

	cout << "num Entries " << b.getNumEntriesInRootDir() << endl;

	int fatSector = b.getNumCopiesFAT() * b.getNumSecFAT();
	int rootStart = b.getNumBytesInReservedSectors() + fatSector;

	d = new DirectoryEntry*[b.getNumEntriesInRootDir()];
	for(int i = 0; i < b.getNumEntriesInRootDir(); i++){
		d[i] = new DirectoryEntry(b, rootStart + (i * 32));
		d[i]->getFileName();
		d[i]->getFileExtension();
	}

}
