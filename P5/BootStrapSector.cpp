#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include "BootStrapSector.h"
#include "byte.h"
using namespace std;

BootStrapSector::BootStrapSector(string file)
{
  readBootStrapSector(file);
}

void BootStrapSector::readBootStrapSector(string fileName)
{
  char buffer[2];
  ifstream file(fileName, ios::binary | ios::in | ios::ate);
  streampos size; 
  
  if(file.is_open())
  {
    size = file.tellg();
    mem = new char[size];
    file.seekg (0, ios::beg);
    file.read(mem, size);
    
  }
  else
  {
    cout << "Read bin file failed" << endl;
  }
  
}
int BootStrapSector::getBytesPerSec()
{
  byte temp1 = mem[11];
  byte temp2 = mem[12];
  byte res = temp1 + temp2;
  res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumClusters()
{
  byte res = mem[13];
  res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumEntriesInRootDir()
{
  byte temp1 = mem[17];
  byte temp2 = mem[18];
  byte res = temp1 + temp2;
  res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumBytesInReservedSectors()
{
  byte temp1 = mem[14];
  byte temp2 = mem[15];
  byte res = temp1 + temp2;
  res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumCopiesFAT()
{
  byte res = mem[16];
  res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumBytesPerCluster()
{
  byte temp1 = mem[11];
  byte temp2 = mem[12];
  byte bytesPerSec = temp1 + temp2;
  bytesPerSec = bytesPerSec.toSmallEnd();

  byte sectorsPerCluster = mem[13];
  sectorsPerCluster = sectorsPerCluster.toSmallEnd();
  
  
  return ((bytesPerSec.toInt())*(sectorsPerCluster.toInt()));
}
byte BootStrapSector::memAccess(int i)
{
  byte temp = mem[i];
  return temp;
}

int main()
{
  BootStrapSector test("samplefat.bin");
  cout << test.memAccess(1) << endl;
  return 0;
}
