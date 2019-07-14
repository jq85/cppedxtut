#include <fstream>
#include <iostream>
#include "tempStat.h"

// Constructor.
tempStat::tempStat(double min/* = 0.0*/, double max/* = 0.0*/)
  : minimum(min), maximum(max)
{

}

// Helper method, to write a tempStat object to a file in binary format.
void tempStat::write(std::ostream & os)
{
  os.write((char*)&minimum, sizeof(double));
  os.write((char*)&maximum, sizeof(double));
}

// Helper method, to read a tempStat object from a file in binary format.
void tempStat::read(std::istream & is)
{
  is.read((char*)&minimum, sizeof(double));
  is.read((char*)&maximum, sizeof(double));
}

// CONTROL POSITION
// Write tempStat at specified index in file stream.
void tempStat::write(std::ostream & os, int index)
{
  std::streampos pos(index * RECORD_SIZE);

  //NOTE: to specify where you want to write to, in Bytes.
  os.seekp(pos);
  std::cout << "About to write record at position" << os.tellp() << std::endl;
  os.write((char*)&minimum, sizeof(double));
  os.write((char*)&maximum, sizeof(double));
}

// CONTROL POSITION
// Read tempStat at specified index in file stram.
void tempStat::read(std::istream &is, int index)
{
  std::streampos pos(index * RECORD_SIZE);

  //NOTE: to specify where you want to read from, in Bytes.
  is.seekg(pos);
  std::cout << "About to read record at position " << is.tellg() << std::endl;
  /*
  * I've called the tellp() method here and the tellg()
  * method here just to illustrate that this method exist.
  * It tells you what is the current port position on thecurrent get
  * position in the file, just to remind you that you can call
  * those methods to see where you're currently at in the file.
  */

  is.read((char*)&minimum, sizeof(double));
  is.read((char*)&maximum, sizeof(double));
}

//NOTE: NON MEMBER FUNCTION: OVERLOADING << OPERATOR FOR MY CLASS
std::ostream &operator << (std::ostream &os, const tempStat &ts)
{
  os << "min: " << ts.minimum << ", max: " << ts.maximum << std::endl;
  return os;
}

//NOTE: NON MEMBER FUNCTION: OVERLOADING >> OPERATOR FOR MY CLASS
std::istream &operator >> (std::istream &is, tempStat &ts)
{
  is >> ts.minimum >> ts.maximum;
  return is;
}
