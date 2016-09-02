Project 5
Avik Bag, John Wang, Tyler Boswell

To run, simply type make. This will create an executable. It takes the file name as an argument to the exec.

make
msdosdir samplefat.bin


The Byte object is implemented to allow byte manipulation. You can extract the upper bit, lower bit, convert from big endian to little endian, and concatenate two separate byte objects since we need it to get the FAT entry that is 1.5 bytes. Byte objects can be simply used with cout to output the values in hex, but can easily be represented in decimal if need be. 

The Bootsector object creates a memory allocation of all the data that is contained within the sample.bin file. each byte is accessible by address, e.g., if you want to access byte 512, you simply have to call the method memAccess associated with the Bootsector object and pass the index as it's argument to get the byte at the location. The return type is a byte object. Also, it contains all the necesary information that is needed to traverse the binary file. 

The DirectoryEntry object is made to to allow for storing directory entries. Each directory comes with 6 relevant fields that we are concerned with for this project. Once we had this set up, we could implement a DirectoryLising object, which was responsible for having a list of DirectoryEntry objects, accessing the mem from BootStrapSector, and parsing the necessary data. One thing to note is that some of the directory names start with a strange character. This is completely normal, as this is called the kludge. This is used to keep track of any deleted directory. We are also listing those directories. 

The DirectoryListing object is made to keep track of the DirectoryEntries. It is also what pulls the relevant info from the samplefat.bin file for each file, such as name and file extension. It goes through each 32 bit chunk in the directory listing and creates a DirectoryEntry for each file. 

To print each file's name, extension, size, date, and time, msdosdir.cpp goes through the DirectoryListing's vector of DirectoryEntries and prints each entry. The amount of files is incremented by one per file, and the file's size is added to a running count of the total file size. These values are printed after each file has been printed.