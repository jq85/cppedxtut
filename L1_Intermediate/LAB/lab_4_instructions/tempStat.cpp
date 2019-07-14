#include <fstream>
#include <iostream>
#include "tempStat.h"

// Constructor.
tempStat::tempStat(std::string name/* = 0.0*/, double donation_amount/* = 0.0*/)
  : name(name), donation_amount(donation_amount)
{

}

// Helper method, to write a tempStat object to a file in binary format.
void tempStat::write(std::ostream & os)
{
  os.write((char*)&name, sizeof(double));
  os.write((char*)&donation_amount, sizeof(double));
}

// Helper method, to read a tempStat object from a file in binary format.
void tempStat::read(std::istream & is)
{
  is.read((char*)&name, sizeof(double));
  is.read((char*)&donation_amount, sizeof(double));
}

// CONTROL POSITION
// Write tempStat at specified index in file stream.
void tempStat::write(std::ostream & os, int index)
{
  std::streampos pos(index * RECORD_SIZE);

  //NOTE: to specify where you want to write to, in Bytes.
  os.seekp(pos);
  std::cout << "About to write record at position" << os.tellp() << std::endl;
  os.write((char*)&name, sizeof(double));
  os.write((char*)&donation_amount, sizeof(double));
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

  is.read((char*)&name, sizeof(double));
  is.read((char*)&donation_amount, sizeof(double));
}

double tempStat::read_last_donation_from_file(std::fstream &ifile)
{
  double last_donation = 0.0;
  // std::ifstream ifile("donation_total.txt");
  if (ifile.is_open())
  {
      std::cout << std::endl << "Starting to read file." << std::endl;
      std::string line;
      while (std::getline(ifile, line))
      {
          // std::cout << line << std::endl;
          this->last_donation = std::stoi(line);
      }

      ifile.close();

      std::cout << "Finished reading text from file1.txt." << std::endl;
  }
  else
  {
      std::cerr << "Couldn't open file1.txt for reading." << std::endl;
  }

  return this->last_donation;
}

void tempStat::append_new_total_to_file(/*std::ofstream &ofile*/)
{
  std::ofstream ofile("donation_total.txt");

  if (!ofile.is_open())
  {
    std::ofstream ofile("donation_total.txt");
  }

  if (ofile.is_open())
  {
      ofile << std::to_string(this->total) << std::endl;
      ofile.close();

      std::cout << "Finished writing text to file1.txt." << std::endl;
  }
  else
  {
    std::cerr << "Couldn't open file1 for writing." << std::endl;
  }
}


double tempStat::add_donation(double amount)
{
  double total = this->last_donation + amount;

  return total;
}



//NOTE: NON MEMBER FUNCTION: OVERLOADING << OPERATOR FOR MY CLASS
std::ostream &operator << (std::ostream &os, const tempStat &ts)
{
  os << "name: " << ts.name << ", donation_amount: " << ts.donation_amount << std::endl;
  return os;
}

//NOTE: NON MEMBER FUNCTION: OVERLOADING >> OPERATOR FOR MY CLASS
std::istream &operator >> (std::istream &is, tempStat &ts)
{
  is >> ts.name >> ts.donation_amount;
  return is;
}
