Project 5
Avik Bag, John Wang, Tyler Boswell

The Byte object is implemented to allow byte manipulation. You can extract the upper bit, lower bit, convert from big endian to little endian, and concatenate two separate byte objects since we need it to get the FAT entry that is 1.5 bytes. Byte objects can be simply used with cout to output the values in hex, but can easily be represented in decimal if need be. 

The Bootsector object creates a memory allocation of all the data that is contained within the sample.bin file. each byte is accessible by address, e.g., if you want to access byte 512, you simply have to call the method memAccess associated with the Bootsector object and pass the index as it's argument to get the byte at the location. The return type is a byte object. Also, it contains all the necesary information that is needed to traverse the binary file. 
