# GETTING AND SETTING THE POSITION IN A STREAM
==============================================

C++ stream objects keep track of the current read/write position in the stream:
  - istream and ifstream objects keep track of the current "get" position.
    You can obtain the current get position by calling the tellg() method,
    and you can modify the current get position by calling the seekg() method.

  - ostream and ofstream objects keep track of the current "put" position.
    You can obtain the current put position by calling the tellp() method,
    and you can modify the current put position by calling the seekp() method.

  - iostream and fstream objects keep track of both the current "get" and "put" positions.
    You can obtain the current get and put positions by calling the tellg() and tellp() methods,
    and you can modify the current get and put positions by calling the seekg() and seekp() methods.

The tellg() and tellp() methods return a std::streampos value:

  std::streampos tellg();
  std::streampos tellp();

The seekg() and seekp() methods are overloaded.
The first version of these methods takes a std::streampos parameter, specifying the seek position from the start of the stream:

  std::istream& seekg (std::streampos pos);
  std::ostream& seekp (std::streampos pos);

The second version of the seekg() and seekp() methods takes two parameters:

  - An std::streamoff parameter, specifying a relative offset.
  - An std::ios_base::seekdir parameter, specifying the offset direction (allowable values are std::ios_base::beg, std::ios_base::cur, and std::ios_base::end):

  std::istream& seekg (std::streamoff off, std::ios_base::seekdir way);
  std::ostream& seekp (std::streamoff off, std::ios_base::seekdir way);

This demonstration illustrates how to get and set the position in a file. The example is based on a file that contains temperature statistics for 12 months in a year. The application allows the user to modify the temperature statistics for a particular month. To achieve this effect, the code uses seekp() to set the put position in the file, then overwrites the data at that location in the file. The code also uses tellp() to tell the user what the put position is, for illustration purposes.
