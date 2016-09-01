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
  byte temp1 = (unsigned char)mem[11];
  byte temp2 = (unsigned char)mem[12];
  byte res = temp2 + temp1;
  //res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumClusters()
{
  byte res = mem[13];
  //res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumEntriesInRootDir()
{
  byte temp1 = (unsigned char)mem[17];
  byte temp2 = (unsigned char)mem[18];
  byte res = temp2 + temp1;

  return res.toInt();
}
int BootStrapSector::getNumReservedSectors()
{
  byte temp1 = (unsigned char)mem[14];
  byte temp2 = (unsigned char)mem[15];
  byte res = temp2 + temp1;
  //res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumCopiesFAT()
{
  byte res = (unsigned char)mem[16];
  //res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumSecFAT()
{
  byte temp1 = (unsigned char)mem[22];
  byte temp2 = (unsigned char)mem[23];
  byte res = temp2 + temp1;
  //res = res.toSmallEnd();

  return res.toInt();
}
int BootStrapSector::getNumBytesPerCluster()
{
  byte temp1 = (unsigned char)mem[11];
  byte temp2 = (unsigned char)mem[12];
  byte bytesPerSec = temp2 + temp1;
  bytesPerSec = bytesPerSec.toSmallEnd();

  byte sectorsPerCluster = (unsigned char)mem[13];
  sectorsPerCluster = sectorsPerCluster.toSmallEnd();
  
  
  return ((bytesPerSec.toInt())*(sectorsPerCluster.toInt()));
}
byte BootStrapSector::memAccess(int i)
{
  byte temp = (unsigned char)mem[i];
  return temp;
}
/*
int main()
{
  BootStrapSector test("samplefat.bin");
  for (int i = 0; i < 50000; i++){
    cout << test.memAccess(i) << " ";
  }
  return 0;
}
*/
