#include "DirectoryEntry.h"
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

DirectoryEntry::DirectoryEntry(int is){
	imageStream = is;
	readDirectoryEntry();
}

BYTE* DirectoryEntry::getFileName(){
	return fileName;
}
BYTE* DirectoryEntry::getFileExtension(){
	return extension;
}
int DirectoryEntry::getTime(){
	return time;
}
int DirectoryEntry::getDate(){
	return date;
}
int DirectoryEntry::getStartCluster(){
	return startCluster;
}
int DirectoryEntry::getFileSize(){
	return fileSize;
}

void readDirectoryEntry(){
	read(imageStream, fileName, 8);
	read(imageStream, extension, 3);
	read(imageStream, attributes, 1);
	read(imageStream, reserved, 10);
	read(imageStream, time, 2);
	read(imageStream, date, 2);
	read(imageStream, startCluster, 2);
	read(imageStream, fileSize, 4);
}
