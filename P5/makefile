CC = g++
FLAG = c++11
MSDOSDIR = msdosdir.cpp BootStrapSector.cpp DirectoryEntry.cpp DirectoryListing.cpp byte.cpp
# TESTING = test.cpp BootStrapSector.cpp DirectoryEntry.cpp byte.cpp
FILE = samplefat.bin

msdosdir : $(MSDOSDIR)
	$(CC) -std=$(FLAG) -o msdosdir $(MSDOSDIR)
