// #include "stdafx.h"
#include <iostream>     // for std::cin, std::cout, etc.
#include <fstream>      // for std::ifstream and std::ofstream.
#include "tempStat.h"   // for our tempStat class.

// Prototypes for helper functions.
void updateStat(int index);
void displayStat(int index);
void displayAllStats();

// Program entry point.
int main()
{
  std::cout << "Temperature stats initially: " << std::endl;
  displayAllStats();

  int index;
  std::cout << "Which month's stats do you want to update [0...11]? ";
  std::cin >> index;

  if((index < 0) || (index >= 12))
  {
    std::cerr << "Invalid index." << std::endl;
  }
  else
  {
    updateStat(index);
    displayStat(index);

    std::cout << std::endl << "Temperature stats finally:" << std::endl;
    displayAllStats();
  }

  return 0;
}

/*
*
*/
void updateStat(int index)
{
  tempStat ts;
  std::cout << "Enter minimum and maximum temperatures: ";
  std::cin >> ts;

  //NOTE: not efficient to open every time.
  std::fstream ofile("tempStats.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::in);
  if(ofile.is_open())
  {
    ts.write(ofile, index);
    ofile.close();
  }
  else
  {
    std::cerr << "Couldn't open tempStats.bin for writing." << std::endl;
  }
}

/*
*
*/
void displayStat(int index)
{
  std::fstream ifile("tempStats.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::in);
  if(ifile.is_open())
  {
    tempStat ts;
    ts.read(ifile, index);
    ifile.close();
  }
  else
  {
    std::cerr << "Couldn't open tempStats.bin for reading." << std::endl;
  }
}

/*
*
*/
void displayAllStats()
{
  //NOTE: fstream because it must read the whole file.
  std::fstream ifile("tempStats.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::in);
  if(ifile.is_open())
  {
    int index = 0;
    while(!ifile.eof())
    {
      tempStat ts;
      ts.read(ifile);//read next record from that location.

      //If you don't read any bytes, effectively that means end file,
      if(ifile.gcount() == 0)
      {
        break; // If no bytes read, we're done.
      }

      // std::cout << "Index " << index << ", tempStat: " << ts << std::endl;
      std::cout << "Index " << index << ", tempStat: " << ts << std::endl;

      index++;
    }
    ifile.close();
  }
  else
  {
    std::cerr << "Couldn't open tempStats.bin for reading." << std::endl;
  }
}
