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

#include "types.h"

class DirectoryEntry {
	public:
		DirectoryEntry(int is);
		BYTE* getFileName();
		BYTE* getFileExtension();
		int getTime();
		int getDate();
		int getStartCluster();
		int getFileSize();

	private:
		void readDirectoryEntry();
		int imageStream;

		BYTE fileName[8];
		BYTE extension[3];
		BYTE attributes[1];
		BYTE reserved[10];
		BYTE time[2];
		BYTE date[2];
		BYTE startCluster[2];
		BYTE fileSize[4];
}
#endif
