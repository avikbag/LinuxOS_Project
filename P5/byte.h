#ifndef BYTE_H
#define BYTE_H

#include<ostream>
using namespace std;

class byte
{
  public:
    byte();
    byte(const byte &b);
    byte(unsigned int inp);
    byte upper();
    byte lower();
    byte toSmallEnd(); // It's defaulted to big Endian, this converts it to little endian 
    const unsigned int raw() const;
    int toInt();
    byte operator+(const byte &b); // meant to concat two hex values. e.g 0xe3 + 0x1a = 0xe31a
    byte operator&(const byte &b);
    byte operator|(const byte &b);
    byte operator<<(int n);
    byte operator>>(int n);
    void operator=(unsigned int b);
    void operator=(char b);
    void operator=(byte b);
  
  private:
    unsigned int data;
    int width;
};
ostream& operator<<(ostream& os, const byte& bt);    

#endif
