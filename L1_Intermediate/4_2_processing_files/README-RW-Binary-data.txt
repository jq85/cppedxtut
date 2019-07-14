# READING AND WRITING BINARY DATA
=================================

You can use file stream objects to read and write binary data in a file.
Binary files are typically smaller than text files,
and can be more efficient to read and write.
These characteristics are particularly beneficial if you have a large amount of data to store.
To read or write binary data to a file, follow these steps:

  - Open the file in binary mode.
    To do this, specify the std::ios::binary mode in the open() method or the file stream constructor.
  - Call the read() or write() method to read or write binary data, respectively.
    Both of these methods take two parameters:
      - The address of the variable to read or write, expressed as a (char*) pointer.
      - The size of the value to read or write, in bytes. You can use the C++ sizeof operator to obtain this value.

CALC BINARY FILE SIZE
Let's see a complete example. In this example, we'll read and write temperature statistics to a file in binary format.
Specifically, the file will store the minimum and maximum temperatures for a particular place for each month in the year.
We'll represent the temperatures as doubles, so the file will contain 24 doubles.
A double is 8 bytes in size, so the file size will be 192 bytes in total.

For convenience, we'll define a class to hold the minimum and maximum temperature statistics for a month.
Here's the full class definition, with an explanation after the code:

    class tempStat
    {
        public:
        // Data members.
        double minimum, maximum;

        // Constructor, initializes the data members to specified values,
        // or to 0.0 if no values are supplied in the client code.
        tempStat(double min = 0.0, double max = 0.0)
            : minimum(min), maximum(max)
        {}

        // Helper method, to write a tempStat object to a file in binary format.
        void write(std::ostream & os)
        {
            os.write((char*)&minimum, sizeof(double));
            os.write((char*)&maximum, sizeof(double));
        }

        // Helper method, to read a tempStat object from a file in binary format.
        void read(std::istream & is)
        {
            is.read((char*)&minimum, sizeof(double));
            is.read((char*)&maximum, sizeof(double));
        }
        // Plus other members, as appropriate.
    };


Note the following points:

- The class contains two double data members. We've defined these data members as public for convenience in the example.
- The constructor initializes the data members to specified values, or to 0.0 if no values are supplied in the client code.
- The write() method encapsulates the task of writing a tempStat object to a file.
  It's not necessary to implement such a method, but it simplifies client code by doing so.
  The method takes an std::ofstream object as a parameter,
  and calls its write() method twice to write the minimum and maximum temperatures to the file.
  In each call, we pass two parameters:
    - The address of the variable to write, converted to a (char*) pointer.
    - The size of the variable in bytes, obtained via the sizeof operator.
- The read() method encapsulates the task of reading a tempStat object from a file.
  The method takes an std::ifstream object as a parameter,
  and calls its read() method twice to read a pair of double values from the file.
  We use the values to set the minimum and maximum values in the tempStat object.

For convenience, we also define >> and << operators to read and write tempStat objects to a stream in text format.
We can use these operators to input and output tempStat objects on the console, for example:

    std::istream& operator >> (std::istream& is, tempStat & ts)
    {
        is >> ts.minimum >> ts.maximum;
        return is;
    }

    std::ostream& operator << (std::ostream & os, const tempStat & ts)
    {
        os << ts.minimum << "," << ts.maximum << std::endl;
        return os;
    }

Now let's look at the client code.
The following code creates 12 tempStat objects containing hard-coded minimum/maximum temperatures,
and writes all the objects to a file in binary format by using the write() helper method in the tempStat class:

    std::ofstream ofile("tempStats.bin", std::ios_base::binary);
    if (ofile.is_open())
    {
        tempStat(-2.5, 7.5).write(ofile);
        tempStat(0, 9.9).write(ofile);
        tempStat(2.5, 11.0).write(ofile);
        tempStat(5.5, 14.5).write(ofile);
        tempStat(7.0, 17.7).write(ofile);
        tempStat(10.5, 23.7).write(ofile);
        tempStat(11.7, 29.5).write(ofile);
        tempStat(7.6, 22.9).write(ofile);
        tempStat(7.2, 21.5).write(ofile);
        tempStat(2.0, 16.0).write(ofile);
        tempStat(-4.7, 12.5).write(ofile);
        tempStat(-1.9, 8.5).write(ofile);

        ofile.close();

        std::cout << "Finished writing binary data to tempStats.bin." << std::endl;
    }
    else
    {
        std::cerr << "Couldn't open tempStats.bin for writing." << std::endl;
    }

The following code reads tempStat objects from the file.
We open the file in binary format, and loop through the file until end-of-file is detected.
We also have an additional if-test each time round the loop, where we call gcount() on the std::ifstream() object.
This determines the number of bytes read in the most recent read() call;
if the number of bytes is zero, it means we've reached the end of file,
in which case we can break out of the loop immediately:

    std::ifstream ifile("tempStats.bin", std::ios_base::binary);
    if (ifile.is_open())
    {
        while (!ifile.eof())
        {
            tempStat ts;
            ts.read(ifile);

            if (ifile.gcount() == 0)
            {
                break;  // If no bytes read, we're done.
            }

            std::cout << "Read temperature stats: " << ts << std::endl;
        }
        ifile.close();

        std::cout << "Finished reading binary data from tempStats.bin." << std::endl;
    }
    else
    {
        std::cerr << "Couldn't open tempStats.bin for reading." << std::endl;
    }
