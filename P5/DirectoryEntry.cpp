#include "DirectoryEntry.h"
#include "BootStrapSector.h"
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cstdio>
#include <fcntl.h>
#include "byte.h"
#include "BootStrapSector.h"

using namespace std;

DirectoryEntry::DirectoryEntry(string fileName): local(fileName){
	cout << "check" << endl;
  //local(fileName);
  //readDirectoryEntry(b, start);
}
/*
void DirectoryEntry::readDirectoryEntry(BootStrapSector b, int start){
	for(int i = 0; i < b.getNumEntriesInRootDir(); i++){
		for(int j = 0; j < 32; j++){
			mem[j] = b.memAccess(start + (i*32) + j);
		}
	}
}
byte* DirectoryEntry::getFileName(){
	byte temp = mem[0];
	for(int i = 1; i < 7; i++){
		temp = temp + mem[i];
	}
	cout << temp << endl;
}
byte* DirectoryEntry::getFileExtension(){
	byte temp = mem[8];
	for(int i = 9; i < 10; i++){
		temp = temp + mem[i];
	}
	cout << temp << endl;
}

int DirectoryEntry::getHour(){

}
int DirectoryEntry::getMin(){

}
int DirectoryEntry::getSec(){

}
int DirectoryEntry::getYear(){

}
int DirectoryEntry::getMonth(){

}
int DirectoryEntry::getDay(){

}
int DirectoryEntry::getStartCluster(){
	
}
int DirectoryEntry::getFileSize(){
	
}*/

int main()
{
  DirectoryEntry d("samplefat.bin");
}
