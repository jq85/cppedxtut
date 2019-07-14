# INTRODUCTION TO FILE STREAMS
==============================

The standard C++ library defines three stream-based classes that allow you to read and write data to/from files using the stream operators >> and <<.
These classes are defined in the <fstream> header file:

- std::ifstream inherits from std::istream, and allows you to read data from a file using the >> operator.
- std::ofstream inherits from std::ostream, and allows you to write data to a file using the << operator.
- std::fstream inherits from both std::istream and std::ostream, and allows you to read and write data to/from a file using the >> and << operators.

All the file stream objects have an open() method that takes a filename as a parameter and opens the specified file.
Likewise, there's a close() method that closes the file when you're finished with it. Consider the following example:

    #include <fstream>

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

        // Use the files...

        // Close the files.
        ofile.close();
        ifile.close();
        iofile.close();
    }

Alternatively, you can rely on the file stream object's constructors and destructors to open/close the file.
Specifically, if you pass the filename into the constructor, then the file is opened immediately.
Likewise, if the file is still open when the destructor is called, then the destructor will close the file. Consider the following example:

    #include <fstream>
    …

    void openCloseFilesImplicitly()
    {
        // Declare file stream objects (files opened implicitly by constructors).
        std::ofstream ofile("file1.dat");
        std::ifstream ifile("file2.dat");
        std::fstream  iofile("file3.dat");

        // Use the files...

    }   // Files closed implicitly by destructors.



# FILE OPEN MODES
=================

When you open a file, either by specifying a filename in the file stream constructor or by calling the open() method explicitly,
you can optionally specify a mode parameter.
The mode is a combination of the following bit flags:

  - std::ios_base::in
    Specifies the file will be opened for input operations.
    This is the default mode for std::ifstream objects.

  - std::ios_base::out
    Specifies the file will be opened for output operations.
    This is the default mode for std::ofstream objects.

  - std::ios_base::binary
    Specifies the file will be opened in binary mode,
    i.e. no formatting will be applied to values when they are read or written.
    For example, the double value 3.14 will be written as an 8-byte double value.
    The default is text mode, whereby values will be formatted as text when they are read or written.
    For example, the double value 3.14 will be written as the four characters '3', '.', '1', and '4'.

  - std::ios_base::ate
    Specifies the initial position for read/write operations is at the end of the file.
    The default initial position for read/write operations is at the start of the file.

  - std::ios_base::app
    Specifies that all output operations will occur at the end of the file,
    thereby preserving the existing content in the file.

  - std::ios_base::trunc
    If you open an existing file for output operations,
    this flag causes the existing content to be deleted and replaced with the new content that you write in your application.


COMBINE FLAGS (|)
You can combine these flags together by using the bitwise OR operator (|).
For example, the following code snippet shows two ways to open an output file in binary mode,
to append new content at the end of the file:

    std::ofstream ofile1;
    ofile1.open("file1.dat", std::ios_base::binary | std::ios_base::app);

    std::ofstream ofile2("file2.dat", std::ios_base::binary | std::ios_base::app);

Note that you don't need to specify the std::ios_base::out bit flag for std::ofstream objects
(or the std::ios_base::in bit flag for std::ifstream objects),
because these modes are assumed for these types of file stream objects.

The default mode for std::fstream objects is std::ios_base::in | std::ios_base::out.
However, if you specify a mode explicitly, then the mode you specify will overwrite the default;
if you want the std::ios_base::in and std::ios_base::out bit flags to apply, then you must reinstate them explicitly.
Consider the following example:

    // Default file mode applies here, i.e. std::ios_base::in | std::ios_base::out.
    std::fstream iofile1("iofile1.dat");

    // File mode is just std::ios_base::binary.
    std::fstream iofile2("iofile2.dat", std::ios_base::binary);

    // File mode is just std::ios_base::binary | std::ios_base::in | std::ios_base::out.
    std::fstream iofile3("iofile3.dat", std::ios_base::binary | std::ios_base::in | std::ios_base::out);

    After you've opened a file, you can call the is_open() method to determine if the file has been opened successfully.
    Here's a simple example:
    if (somefile.is_open())
    {
        // File opened OK, so use it…

        // Close the file when we're done.
        somefile.close();
    }
    else
    {
        std::cerr << "Couldn't open file" << std::endl;
    }



# READING AND WRITING TEXT DATA
===============================

The std::ifstream class inherits from std::istream,
which means you can use the >> operator to read data from a file.
Likewise, the std::ofstream class inherits from std::ostream,
which means you can use the << operator to write data to a file.

READ LINE
In addition to the >> and << operators, you can also use the other members defined in the std::istream and std::ostream classes.
In the same way, you can use methods such as std::getline() to read an entire line of text from a file stream object.

WRITE
The following code example shows how to write several lines of text to a file.
We create an std::ofstream object, which implicitly opens the file in output mode.
We then use the << operator, inherited from std::ostream, to write text to the file.
At the end of the code snippet, we close the file so that it can be accessed by other applications (or reopened in a different mode later in our application):

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

If you run the code above, it will write the following contents to file1.txt:

Here is line 1.
Here is line 2.
Here is line 3.


READ FILE
The following code example shows how to read the contents of file1.txt.
We create an std::ifstream object, which implicitly opens the file in input mode.
We then set up a loop and call std::getline() on each loop iteration, to read an entire line of text at a time.
std::getline() returns false at the end of file, which terminates the loop:

    std::ifstream ifile("file1.txt");
    if (ifile.is_open())
    {
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
