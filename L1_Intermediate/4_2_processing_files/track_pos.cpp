// #include <fstream>
#include <iostream>

int main()
{
  std::streampos tellg();
  std::streampos tellp();


  std::istream& seekg (std::streampos pos);
  std::ostream& seekp (std::streampos pos);


  std::istream& seekg (std::streamoff off, std::ios_base::seekdir way);
  std::ostream& seekp (std::streamoff off, std::ios_base::seekdir way);
  return 0;
}
