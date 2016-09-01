#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cstdio>
#include <fcntl.h>
#include <string>
#include "byte.h"
#include "DirectoryEntry.h"
//#include "BootStrapSector.h"

using namespace std;

DirectoryEntry::DirectoryEntry()
{
  _time = 0;
  _date = 0;
  _startCluster = 0;
  _fileSize = 0;
  _name = "";
  _ext = "";
}

DirectoryEntry::DirectoryEntry(int time, int date, int startCluster, int fileSize, string name, string ext)
{
  _time = time;
  _date = date;
  _startCluster = startCluster;
  _fileSize = fileSize;
  _name = name;
  _ext = ext;
}

DirectoryEntry::DirectoryEntry(const DirectoryEntry &d)
{
  _time = d._time;
  _date = d._date;
  _startCluster = d._startCluster;
  _fileSize = d._fileSize;
  _name = d._name;
  _ext = d._ext;
}
int DirectoryEntry::getTime()
{
  return _time;
}
int DirectoryEntry::getDate()
{
  return _date;
}
int DirectoryEntry::getStartCluster()
{
  return _startCluster;
}
int DirectoryEntry::getFileSize()
{
  return _fileSize;
}

string DirectoryEntry::getFileName()
{
  return _name;
}
string DirectoryEntry::getFileExt()
{
  return _ext;
}
/*
int main()
{
  DirectoryEntry d[10];
  DirectoryEntry temp;
  
  for(int i = 0; i < 10; i ++)
  {
    DirectoryEntry temp(i, i, i, i, "hi", "bye");
    d[i] = temp;
  }
  for(int i = 0; i < 10; i ++)
  {
    //DirectoryEntry temp(i, i, i, i, "hi", "bye");
    cout << d[i].getTime() << endl;
  }

}*/
