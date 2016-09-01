#include <fcntl.h>
#include <iostream>
#include <unistd.h>

#include "byte.h"
#include "DirectoryEntry.h"
#include "BootStrapSector.h"

using namespace std;

void extract(BootStrapSector *b, DirectoryEntry *d, int dataStart) {
    byte fileName = d->getFileName();
    byte fileExtension = d->getFileExtension(); 
    int cluster = d->getStartCluster();

    while (cluster < 0xFF8) { //until last cluster
        //read data from the cluster
        //get the next next cluster
        // cluster = nextCluster;
    }
}

int main(int argc, char *argv[]) {
    int numEntries;
    int rootDirBytes;
    int fatBytes;
    int dataStart;
    int rootStart;

    BootStrapSector *b = NULL;
    DirectoryEntry *d = NULL;
    DirectoryEntry **entries = NULL;

    if(argc != 2) {
        cout << "Usage: " << argv[0] << " FILE" << endl;
        return -1;
    }

    b = new BootStrapSector(argv[1]);
    
    fatBytes = b->getNumCopiesFAT() * b->getNumSecFAT() * b->getBytesPerSec();
    numEntries = b->getNumEntriesInRootDir();
    rootDirBytes = numEntries * 32;
    rootStart = b->getNumBytesInReservedSectors() + fatBytes;
    dataStart = rootStart + rootDirBytes;

    entries = new DirectoryEntry*[numEntries];

    for(int i = 0; i < numEntries; i ++) {
        entries[i] = new DirectoryEntry(argv[1], rootStart[i * 32]);
    }
    for (int j = 0; j < numEntries; j ++) {
        extract(b, entries[j], dataStart);
    }
    
}
