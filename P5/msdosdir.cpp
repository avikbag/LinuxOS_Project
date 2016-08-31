#include <fcntl.h>
#include <iostream>
#include <unistd.h>

#include "byte.h"
#include "DirectoryEntry.h"
#include "BootStrapSector.h"

using namespace std;

int main(int argc, char *argv[]){

	BootStrapSector *b = NULL;
	DirectoryEntry *d = NULL;

	byte* serialNumber;
	byte* volLabel;
	byte* fileName;
	byte* fileExt;
	int time;
	int date;
	int numEntries;
	int rootStart;
	int fileSize;
	int fatSectors;
	int totalFiles = 0; //init num of files
	int totalSize = 0;

	if(argv != 2){
		printf("Usage: %s FILE\n", argv[0]);
		return -1;
	}
	
	b = new BootStrapSector(argv[1]);
	numEntries = b->getNumEntriesInRootDir();
	volLabel = b->getVolumeLabel();
	serialNumber = b->getVolumeSerialNumber();
	cout << "Volume name is " << volLabel << endl;
	cout << "Volume Serial Number is " << serialNumber << endl;
	

	//FAT_Sectors = Number_Of_FATs * Sectors_Per_FAT
	//Root_Starting_Sector = Reserved_Sectors + FAT_Sectors
	//this is how you get the starting position of the directories
	fatSectors = b->getNumCopiesFAT() * b->getSectorsPerFAT();
	rootStart = b->getReservedSectors() + fatSectors;
	
	d = new DirectoryEntry[numEntries];

	for(int i = 0; i < numEntries; i ++){
		d[i] = new DirectoryEntry(argv[1], rootStart(i * 32)); // *32 is so when we are done with one entry the next one is 32 bits away
		fileName = d[i]->getFileName();
		fileExt = d[i]->getFileExtension();
		fileSize = d[i]->getFileSize();
		time = d[i]->getTime();
		date = d[i]->getDate();
		//time needs to be converted
		//Time (coded as Hour*2048+Min*32+Sec/2)
		//Date (coded as Year-1980)*512+Month*32+Day)

		cout << fileName << " " << fileExt << " " << fileSize << " " << time << " " << date << endl; 

		totalFile++;
		totalSize += d[i]->getFileSize();
	}
	
	cout << totalFiles << " file(s) " << totalSize << " bytes" << endl;

}
