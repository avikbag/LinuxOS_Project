/**
 * BootStrapSector is the first 512 bytes of the FAT.
 * Two byte fields are little-endian
 *
 * The format of this sector is:
 * byte(s) contents
 * ------- -------------------------------------------------------
 *  0-2 first instruction of bootstrap routine
 *  3-10 OEM name
 *  11-12 number of bytes per sector
 *  13 number of sectors per cluster
 *  14-15 number of reserved sectors
 *  16 number of copies of the file allocation table
 *  17-18 number of entries in root directory
 *  19-20 total number of sectors
 *  21 media descriptor byte
 *  22-23 number of sectors in each copy of file allocation table
 *  24-25 number of sectors per track
 *  26-27 number of sides
 *  28-29 number of hidden sectors
 *  30-509 bootstrap routine and partition information
 *  510 hexadecimal 55
 *  511 hexadecimal AA
 */
 
#ifndef BOOTSTRAP_SECTOR_H
#define BOOTSTRAP_SECTOR_H

#include<string>
#include"byte.h"
using namespace std;

class BootStrapSector {
	public:
           BootStrapSector(string name);
           int getBytesPerSec();
           int getNumClusters();
           int getNumEntriesInRootDir();
           int getNumBytesInReservedSectors();
           int getNumCopiesFAT();
           int getNumBytesPerCluster();
           byte memAccess(int i);
           /*
           BYTE* getVolumeLabel();
           BYTE* getVolumeSerialNumber();
           BYTE* getFormatType();
		*/
	private:
            void readBootStrapSector(string fileName);
            char* mem;
            
};

#endif
