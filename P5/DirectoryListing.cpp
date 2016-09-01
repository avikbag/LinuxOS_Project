#include <string>
#include <iostream>
#include <vector>
#include "byte.h"
#include "BootStrapSector.h"
#include "DirectoryEntry.h"
#include "DirectoryListing.h"

DirectoryListing::DirectoryListing(string fileName) : _local(fileName)
{
  // Simply sets up the Bootsector object for memory access.
  // Sets the number of bytes to skip to reach directory area
  //cout << _local.getNumCopiesFAT() << endl;
  //cout << _local.getNumSecFAT() << endl;
  //cout << _local.getBytesPerSec() << endl;
  //cout << _local.getNumReservedSectors() << endl;
  //cout << _local.getNumEntriesInRootDir() << endl;

  _offset = (_local.getNumCopiesFAT() * _local.getNumSecFAT() * _local.getBytesPerSec()) + (_local.getBytesPerSec() * _local.getNumReservedSectors());
  //cout << _offset << endl;
  //_offset = 9728;
  read();
}

void DirectoryListing::read()
{
  vector<byte> dirChunks;
  for(int i = 0; i < _local.getNumEntriesInRootDir(); i++)
  {
    for(int j = 0; j < 32; j++)
    {
      dirChunks.push_back(_local.memAccess(_offset + (i*32) + j));
    }
    cout << getHour(dirChunks) << " " << getMin(dirChunks) << " " << getSec(dirChunks) << endl;
    //DirectoryEntry temp(getName(dirChunks));
    dirChunks.clear();
  }
}
string DirectoryListing::getName(vector<byte> b)
{
  string str;
  for(int i = 0; i < 7; i++)
  {
    str+=(char)b[i].toInt();
  }
  //cout << b[0].toInt() << " ";
  if(b[0].toInt() != 0)
    return str;
}
string DirectoryListing::getExt(vector<byte> b)
{
	string str;
  for(int i = 8; i < 11; i++){
    str+=(char)b[i].toInt();
  }
  //cout << b[8].toInt() << " ";
  if(b[8].toInt() != 0){
    return str;
  }
}
int DirectoryListing::getFileSize(vector<byte> b)
{
  int size;
  for(int i = 28; i < 32; i++){
    size+=(char)b[i].toInt();
  }
  if(b[28].toInt() != 0){
    return size;
  }
}
int DirectoryListing::getHour(vector<byte> b)
{
  return (b[23] >> 3).toInt();
}
int DirectoryListing::getMin(vector<byte> b)
{
  return (((b[23] & 0x07) << 3) + (b[24] >> 5)).toInt();
}
int DirectoryListing::getSec(vector<byte> b)
{
  return (b[24] & 0x1F).toInt();
}
int DirectoryListing::getYear(vector<byte> b)
{
  return 1980 + ((b[26] >> 1)).toInt();
}
int DirectoryListing::getMonth(vector<byte> b)
{
  return (((b[26] & 0x01) << 3) + (b[25] >> 5)).toInt();
}
int DirectoryListing::getDay(vector<byte> b)
{
  return (b[25] & 0x1F).toInt();
}

int main()
{
  DirectoryListing("samplefat.bin");
  return 0;
}
