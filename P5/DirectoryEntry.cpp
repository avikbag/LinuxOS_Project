#include "DirectoryEntry.h"
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cstdio>
#include <fcntl.h>
#include "byte.h"

using namespace std;

DirectoryEntry::DirectoryEntry(Sting file, int start){
	readDirectoryEntry(file, start);
}
void DirectoryEntry::readDirectoryEntry(string fileName, int start){
	char buffer[2];
	ifstream file(fileName, ios::binary | ios::in | ios::ate);
	streampos size;
	if(file.is_open()){
		size = file.tellg();
		mem = new char[size];
		file.seekg (0, ios::beg);
		file.read(mem, size);
	} else {
		cout <<"Read bin file failed" << endl;
	}
}
byte* DirectoryEntry::getFileName(){
	return fileName;
}
byte* DirectoryEntry::getFileExtension(){
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

