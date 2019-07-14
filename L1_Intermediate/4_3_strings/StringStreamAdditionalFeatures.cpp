#include <iostream>
#include <sstream>
#include "tempStat.h"




int main()
{
  std::ostringstream oss(std::ios_base::binary);

  tempStat(-2.5, 7.5).write(oss);
  tempStat(0, 9.9).write(oss);
  tempStat(2.5, 11.0).write(oss);
  tempStat(5.5, 14.5).write(oss);
  tempStat(7.0, 17.7).write(oss);
  tempStat(10.5, 23.7).write(oss);
  tempStat(11.7, 29.5).write(oss);
  tempStat(7.6, 22.9).write(oss);
  tempStat(7.2, 21.5).write(oss);
  tempStat(2.0, 16.0).write(oss);
  tempStat(-4.7, 12.5).write(oss);
  tempStat(-1.9, 8.5).write(oss);
  //NOTE: the ostringstream has been building up a string in memory in a string buffer.
  // So the input stringstream is going to be reading from that string, in binary format.
  std::istringstream iss(oss.str(), std::ios_base::binary);
  while(!iss.eof())//eof: end of file
  {
    tempStat ts;
    ts.read(iss);// this statement here will read from the input stream. It'll attempt to perform a binary read.

    if(iss.gcount() == 0)
    {
      break; // If no bytes read, we're done.
    }
    std::cout << "Read temperature stats: " << ts;
  }

  return 0;
}
