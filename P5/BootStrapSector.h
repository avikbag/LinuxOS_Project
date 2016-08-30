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

#include "types.h"

class BootStrapSector {
	public:
           BootStrapSector(int is);
           int getNumBytesInFAT();
           int getNumClusters();
           int getNumEntriesInRootDir();
           int getNumBytesInReservedSectors();
           int getNumCopiesFAT();
           int getNumBytesPerCluster();
           BYTE* getVolumeLabel();
           BYTE* getVolumeSerialNumber();
           BYTE* getFormatType();
		
	private:
            void readBootStrapSector();
            
            int imageStream;
            
            BYTE firstInstruction[3];  // This is often a jump instruction to the boot sector code itself
            BYTE OEM[8];		
            BYTE numBytesPerSector[2];
            BYTE numSectorsPerCluster[1];
            BYTE numReservedSectors[2];
            BYTE numCopiesFAT[1];
            BYTE numEntriesRootDir[2];
            BYTE numSectors[2];
            BYTE mediaDescriptor[1];
            BYTE numSectorsInFAT[2];
            BYTE numSectorsPerTrack[2];
            BYTE numSides[2];
            BYTE numHiddenSectors[2];
            BYTE formatType[8]; // FAT12 or FAT16 in this program
            BYTE hex55AA[2];	// the last bytes of the boot sector are, by definition, 55 AA.  This is a sanity check.
            BYTE volumeLabel[11];
            BYTE volumeSN[4];
};

#endif
