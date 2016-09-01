/**
 *	Directory Entry for FAT
 *  Two byte fields are little-endian
 *
 *	The format of this sector is:
 *	Byte(s) contain
 *	--------------------------------------------------------------------------
 *		0-7 Filename
 *		8-10 Extension
 *		11 Bit Field for Attributes
 *		12-21 Reserved
 *		22-23 Time
 *		24-25 Date
 *		26-27 Starting Cluster Number
 *		28-31 File Size (in Bytes)
 */

#ifndef DIRECTORY_ENTRY_H
#define DIRECTORY_ENTRY_H

#include "byte.h"
//#include "BootStrapSector.h"
#include<string>

class DirectoryEntry {
	public:
		DirectoryEntry();
    DirectoryEntry(int time, int date, int startCluster, int fileSize, string name, string ext);
    DirectoryEntry(const DirectoryEntry &d);
		string getFileName();
		string getFileExt();
		int getTime();
		int getDate();
		int getStartCluster();
		int getFileSize();

	private:
    string _name;
    string _ext;
    int _time;
    int _date;
    int _startCluster;
    int _fileSize;
};
#endif
