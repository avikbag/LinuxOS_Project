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
#define BIRECTORY_ENTRY_H

#include "byte.h"

class DirectoryEntry {
	public:
		DirectoryEntry(String fileName, int start);
		byte* getFileName();
		byte* getFileExtension();
		int getTime();
		int getDate();
		int getStartCluster();
		int getFileSize();

	private:
		void readDirectoryEntry(string fileName, int start);
		char* mem;
}
#endif
