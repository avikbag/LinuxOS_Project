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
  cout << _offset << endl;
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
    setName(dirChunks);
    dirChunks.clear();
  }
}
void DirectoryListing::setName(vector<byte> b)
{
  string str;
  for(int i = 0; i < 11; i++)
  {
    //cout << (char)b[i].toInt() << " " ;
    str+=(char)b[i].toInt();
  }
  //cout << b[0].toInt() << " ";
  if(b[0].toInt() != 0)
    cout << str << endl;
  str = "";
}

int main()
{
  DirectoryListing("samplefat.bin");
  return 0;
}

