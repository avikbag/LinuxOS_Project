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
  _hour = 0;
  _min = 0;
  _sec = 0;
  _day = 0;
  _month = 0;
  _year = 0;
  _startCluster = 0;
  _fileSize = 0;
  _name = "";
  _ext = "";
}

DirectoryEntry::DirectoryEntry(int hour, int min, int sec, int day, int month, int year, int startCluster, int fileSize, string name, string ext)
{
  _hour = hour;
  _min = min;
  _sec = sec;
  _day = day;
  _month = month;
  _year = year;
  _startCluster = startCluster;
  _fileSize = fileSize;
  _name = name;
  _ext = ext;
}

// DirectoryEntry::DirectoryEntry(const DirectoryEntry &d)
// {
//   _time = d._time;
//   _date = d._date;
//   _startCluster = d._startCluster;
//   _fileSize = d._fileSize;
//   _name = d._name;
//   _ext = d._ext;
// }
int DirectoryEntry::getHour()
{
    return _hour;
}
int DirectoryEntry::getMin()
{
    return _min;
}
int DirectoryEntry::getSec()
{
    return _sec;
}
int DirectoryEntry::getDay()
{
    return _day;
}
int DirectoryEntry::getMonth()
{
    return _month;
}
int DirectoryEntry::getYear()
{
    return _year;
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
void DirectoryEntry::print()
{
  cout << _name << " " << _ext << " " << _fileSize << " " << _month << "-"<< _day << "-" << _year << " " << _hour << ":" << _min << endl;
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
