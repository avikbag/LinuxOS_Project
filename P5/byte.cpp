#include "byte.h"
#include<string>
#include<iostream>
#include<iomanip>

byte::byte()
{
  data = 0;
  width = 0;
}
byte::byte(unsigned int inp)
{
  data = inp;
  width = 2;
}
byte::byte(const byte &b)
{
  data = b.raw();
  width = b.width;
}
byte byte::operator&(const byte &b)
{
  byte temp = this->data & b.data;
  return temp;
}
byte byte::operator|(const byte &b)
{
  byte temp = this->data | b.data;
  return temp;
}
byte byte::operator+(const byte &b)
{
  byte temp = (this->data << (4*(b.width))) | b.data;
  width += b.width;
  temp.width = width;
  return temp;
}
const unsigned int byte::raw() const
{
  return data;
}
ostream& operator<<(ostream& os, const byte& bt)
{
  os << setfill('0') << setw(2) << hex << bt.raw();
  return os;
}
void byte::operator=(unsigned int b)
{
  data = b;
  width = 2;
}
void byte::operator=(char b)
{
  data = (unsigned char)b;
  width = 2;
}
void byte::operator=(byte b)
{
  data = b.data;
  width = b.width;
}
byte byte::operator<<(int n)
{
  byte temp;
  data = data << n;
  temp = data;
  return data;
}
byte byte::operator>>(int n)
{
  byte temp;
  data = data >> n;
  temp = data;
  return data;
}
byte byte::upper()
{
  byte temp = (data & 0xf0);
  width = 1;
  return temp;
}
byte byte::lower()
{
  byte temp = (data & 0x0f);
  width = 1;
  return temp;
}
byte byte::toSmallEnd()
{
  byte temp;
  byte left  = (0xf << ((width-1) * 4));
  byte right = 0xf;
  byte res = 0x0;
  byte rightVal, leftVal;
  //cout << "test" << hex << data << endl;
  int shft = width - 1;
  for(int i = 0; i < width/2; i++)
  {
    left >> (width * i);
    right << (width * i);

    rightVal = right & data;
    leftVal = left & data;

    rightVal = rightVal << (shft*4);
    leftVal = leftVal >> (shft*4);
    
    res = res | leftVal;
    res = res | rightVal;
    shft -= 2;
  }
  //cout << "fin" << dec << res.data << endl;
  data = res.data;
  return res;
}
int byte::toInt()
{ 
  return data;
}
/*
int main()
{
  byte a = 0x11;
  byte b = 0x02;
  byte c = (a + b);
  c = c.toSmallEnd();
  cout << c << endl;
  return 0;
}
*/
