/**
 *  Directory Entry for FAT
 *  Two byte fields are little-endian
 *
 *  The format of this sector is:
 *  Byte(s) contain
 *  --------------------------------------------------------------------------
 *    0-7 Filename
 *    8-10 Extension
 *    11 Bit Field for Attributes
 *    12-21 Reserved
 *    22-23 Time
 *    24-25 Date
 *    26-27 Starting Cluster Number
 *    28-31 File Size (in Bytes)
 */

#ifndef DIRECTORY_LISTING_H
#define DIRECTORY_LISTING_H

#include "byte.h"
#include "BootStrapSector.h"
#include "DirectoryEntry.h"
#include <string>
#include <vector>

class DirectoryListing {
  public:
    DirectoryListing(string fileName);
    
  private:
    void read();
    string getName(vector<byte> b);
    int _offset;
    BootStrapSector _local;
    vector<DirectoryEntry> _dirs;
};
#endif
