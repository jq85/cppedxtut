#include <fstream>
#include <iostream>

void openCloseFilesExplicitly()
{
    // Declare file stream objects (files aren't opened yet).
    std::ofstream ofile;
    std::ifstream ifile;
    std::fstream  iofile;

    // Open the files.
    ofile.open("file1.dat");    // Opens file1.dat for writing.
    ifile.open("file2.dat");    // Opens file2.dat for reading.
    iofile.open("file3.dat");   // Opens file3.dat for reading/writing.

    // Close the files.
    ofile.close();
    ifile.close();
    iofile.close();

    // Use the files...
    if (ofile.is_open())
    {
        // File opened OK, so use it…

        // Close the file when we're done.
        ofile.close();
    }
    else
    {
        std::cerr << "File not open" << std::endl;
    }
}


void openCloseFilesImplicitly()
{
    // Declare file stream objects (files opened implicitly by constructors).
    std::ofstream ofile("file1.dat");
    std::ifstream ifile("file2.dat");
    std::fstream  iofile("file3.dat");

    // Use the files...

}   // Files closed implicitly by destructors.


void writeToFile()
{
  std::ofstream ofile("file1.txt");
  if (ofile.is_open())
  {
      ofile << "Here is line 1." << std::endl;
      ofile << "Here is line 2." << std::endl;
      ofile << "Here is line 3." << std::endl;
      ofile.close();

      std::cout << "Finished writing text to file1.txt." << std::endl;
  }
  else
  {
      std::cerr << "Couldn't open file1.txt for writing." << std::endl;
  }
}


void readFile()
{
  std::ifstream ifile("file1.txt");
  if (ifile.is_open())
  {
      std::cout << std::endl << "Starting to read file." << std::endl;
      std::string line;
      while (std::getline(ifile, line))
      {
          std::cout << line << std::endl;
      }

      ifile.close();

      std::cout << "Finished reading text from file1.txt." << std::endl;
  }
  else
  {
      std::cerr << "Couldn't open file1.txt for reading." << std::endl;
  }
}


void writePeople()
{
  std::ofstream ofile("peopleFile.txt");
  if (ofile.is_open())
  {
      ofile << "John" << " " << 42 << " " << 1.67 << std::endl;
      ofile << "Jane" << " " << 41 << " " << 1.54 << std::endl;
      ofile << "Bill" << " " << 35 << " " << 1.82;

      ofile.close();

      std::cout << "Finished writing text to peopleFile.txt." << std::endl;
  }
  else
  {
      std::cerr << "Couldn't open peopleFile.txt for writing." << std::endl;
  }
}


int main()
{

  openCloseFilesExplicitly();

  openCloseFilesImplicitly();

  writeToFile();

  readFile();

  writePeople();

  return 0;
}
