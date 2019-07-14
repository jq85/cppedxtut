# MODULE INTRODUCTION
=====================

The reason we titled this opening section as Stream I/O is because input/output operations in C++ occur in streams.
Streams are essentially a sequence of bytes that are sent from device to device.
A device can refer to an input device such as a keyboard, a disk drive or even across the network or output devices such as display screens, printers, etc.

These streams are typically raw bytes but they have meaning within the context of an application.
Consider a Microsoft Word document being opened from disk.
If you attempt to open it using a generic text editor, you won't see the proper representation of the information stored in the document.
Word uses many different formatting characters and other information that specifies how the document should appear inside the Microsoft Word application.
Opening it in Microsoft Word, the stream of bytes now have the actual representation of the bytes and the text data and formatting data are properly separated.



# INTRODUCTION TO STREAMS
=========================

C++ defines a standard iostream library, which allows you to input and output data to the console using << and >> operators.
We've seen some simple examples of these operators already. Here's another example, which asks the user to enter a couple of numbers and outputs their product:

    #include <iostream>
    …
    double unitPrice;
    int quantity;

    std::cout << "What is the unit price? ";
    std::cin >> unitPrice;

    std::cout << "How many do you want? ";
    std::cin >> quantity;

    std::cout << "Total cost is " << unitPrice * quantity << std::endl;


cin / cout / cerr
------------------
cin and cout are predefined objects in the std namespace.
There's also a predefined object called cerr, which is handy for outputting error messages.
These three objects are defined in the <iostream> header file.

  - cin is an instance of the istream class, and allows you to perform input from the stdin device.
  - cout is an instance of the ostream class, and allows you to perform output to the stdout device.
  - cerr is another instance of the ostream class, and allows you to perform output to the stderr device.

We'll take a closer look at the istream and ostream classes in the next topic.

**Note:** std::endl outputs a newline character to the output stream. Technically speaking, std::endl is a manipulator. We discuss manipulators later in this section.



# A CLOSER LOOK AT istream AND ostream
======================================

istream and ostream aren't actually classes in their own right.
Rather, they are typedefs (i.e. aliases) that represent character-based instantiations of the "basic_istream and basic_ostream template classes" respectively:

  - typedef basic_istream<char> istream;
  - typedef basic_ostream<char> ostream;

The basic_istream class defines a suite of operator >> functions that allow you to input values into built-in types.
The following example shows how to input values for several built-in types:

    short s;
    std::cin >> s;

    int i;
    std::cin >> i;

    long l;
    std::cin >> l;

    unsigned short us;
    std::cin >> us;

    unsigned int ui;
    std::cin >> ui;

    unsigned long ul;
    std::cin >> ul;

    float f;
    std::cin >> f;

    double d;
    std::cin >> d;

    long double ld;
    std::cin >> ld;

    bool b;
    std::cin >> b;  // You must enter 0 or 1

    void * ptr;
    std::cin >> ptr;  // You can enter an address, e.g. FFFF


Similarly the basic_ostream class defines a suite of operator << functions that allow you to output built-in type values.
For example, we can output all the variables from the previous code listing as follows:

    std::cout
        << s   << std::endl
        << i   << std::endl
        << l   << std::endl
        << ui  << std::endl
        << ul  << std::endl
        << f   << std::endl
        << d   << std::endl
        << ld  << std::endl
        << b   << std::endl
        << ptr << std::endl;



# INPUTTING AND OUTPUTTING STRINGS
===================================

The std::string class, defined in the <string> header file, defines >> and << operators
that allow you to input and output strings to/from a stream. Here's a simple example:

    #include <iostream>
    #include <string>
    …
    std::string s;
    cin >> s;
    std::cout << "Your string is " << s << std::endl;

Note that the >> operator inputs a single word, i.e. it stops at the first whitespace character. If you want to input an entire line of text, you should use the std::getline() function instead. This function takes two parameters:

- The input stream, from which you want to get the input
- The std::string object, into which you want to store the value

The following example shows how to use std::getline(). The code snippet allows the user to enter his/her full name and address.

    std::string name;
    std::cout << "Full name: ";
    std::getline(std::cin, name);

    std::string address;
    std::cout << "Full address: ";
    std::getline(std::cin, address);

    std::cout
        << name << std::endl
        << address << std::endl;



# EXTENDING STREAMS TO SUPPORT CUSTOM CLASSES
==============================================

NO SUPPORT FOR CUSTOM CLASSES
The istream and ostream classes support input and output for all the basic types,
but obviously they don't have any inherent support for your own custom classes.
For example, if you define a point class, then you can't automatically input and output point objects to a stream.
The following code would give compiler errors:

    class point { … };
    point p1;
    std::cin >> p1;    // Compiler error, no operator >> function for point.
    std::cout << p1;   // Compiler error, no operator << function for point.


CUSTOM FUNCTIONS FOR << >>
The good news is that you can easily define custom operator >> and operator << functions
to support stream input/output for custom classes.
The techniques are idiomatic, i.e. once you've seen how to define operator >> and operator << for one class type,
then the syntax is basically the same for all other class types.

Let's see a complete example. Imagine we want to extend stream I/O to support the following simple point class (note the x and y data members are public here, for simplicity):

    class point
    {
    public:
        int x, y;

        // Plus other members, as appropriate.
    };

Given this class, you can define a custom operator>> function as follows:

    std::istream & operator >> (std::istream & is, point & p)
    {
        is >> p.x >> p.y;
        return is;
    }


Note the following points:

- The function must be named operator >>.
  This is an example of operator overloading in C++,
  whereby you can extend the meaning of standard operators to support your own custom types.

- The function must receive two parameters.
  The first parameter must be a std::istream reference,
  and represents the input stream from which the values will be obtained (e.g. std::cin).
  The second parameter is a point reference here, and represents the object that will be populated with input from the stream.

- Inside the function, we use the istream object just like we'd use std::cin in normal code.
  Specifically, we get the x and y integer values separately.

- The function must return a std::istream object by reference.
  This allows client code to use the >> operator in a cascaded fashion.
  For example, client code can ask the user to enter two point objects as follows:

        point p1, p2;
        std::cout << "Please enter two points: ";
        std::cin >> p1 >> p2;

In a similar way, you can define a custom operator << function as follows:

    std::ostream & operator << (std::ostream & os, const point & p)
    {
        os << "[" << p.x << "," << p.y << "]";
        return os;
    }


Note the following points:

  - The function must be named operator <<.

  - The function must receive two parameters.
    The first parameter must be a std::ostream reference,
    and represents the output stream where values will be output (e.g. std::cout).
    The second parameter is a const point reference here,
    and represents the object that will be output to the stream.

  - Inside the function, we use the ostream just like we'd use std::cout in normal code.
    Specifically, we output the point in a format [x,y].

  - The function must return a std::ostream object by reference.
    This allows client code to use the << operator in a cascaded fashion.
    For example, client code can output two point objects as follows:

    std::cout
    << "Here are your points..." << std::endl
    << p1 << std::endl
    << p2 << std::endl;



# MANIPULATORS
===============

You can format the way output is displayed on a stream.
For example, you can specify the minimum width for a value when it's displayed,
and whether the value should be left-aligned or right-aligned in that field width.

ENDL
The way you control stream formatting is by using manipulators.
Manipulators are predefined objects that you pass to the stream, to obtain the formatting effect you desire.
The simplest example of a manipulator is std::endl, which tells the stream to output an end-of-line character:

    std::cout << "Hello world" << std::endl;


FLUSH
Another simple example is std::flush, which tells the stream to flush its internal buffer to the physical device (e.g. the console) immediately.
This is useful if you are displaying debugging information, because it ensures your debug message is displayed immediately (e.g. before the program might crash later on):

    std::cout << "Here is a debug message, the value of x is " << x << std::flush;


Manipulators such as std::endl and std::flush don't take any parameters, and are defined in the <iostream> header file.
There are other manipulators that do take parameters, and these are defined in the <iomanip> header file.
A simple example is std::setw, which sets the minimum field width for the next value displayed on the stream.
To use parameterized manipulators, you must include the <iomanip> header file in your code (as well as <iostream>, of course):

    #include <iomanip>// Necessary for parameterized manipulators.
    #include <iostream>   // Necessary for general stream I/O definitions.
    std::cout << std::setw(10) << -123.45 << std::endl;


The following demonstrations show how to achieve these formatting effects:

  - Setting the field width
  - Justifying a value within a field width
  - Formatting floating-point values
  - Additional miscellaneous formatting techniques


# Setting Field Width Demo
==========================
The std::setw() manipulator sets the minimum field width for the next value displayed.
Here's a simple example, which displays a text value in a minimum field width of 10 characters:

    const char * message = "wibble";
    std::cout << "[" << std::setw(10) << message << "]" << std::endl;

Note that std::setw() only applies to the next value.
The default minimum field width is 0 characters.
std::setw() does not cause truncation – if the value exceeds the minimum field width, it will be displayed in full.

This demonstration illustrates the use of std::setw().



# OUTPUT FORMATTING DEMO
========================
If you set a minimum field width for a value, the value is right-justified by default.
To take control of justification, use the std::left and std::right manipulators as follows:

    std::cout << std::left << std::setw(10) << "hello" << "world" << std::endl;
    std::cout << std::right << std::setw(10) << "hello" << "world" << std::endl;

There's also a manipulator called std::internal, which justifies numeric values within the field width.
The + or – sign is left-justified at the start of the field with, and the number itself is right-justified at the end of the field width:

    std::cout << std::internal << std::setw(10) << -123.45 << std::endl;

Note that std::left, std::right, and std::internal apply to all subsequent outputs.
This demonstration illustrates the use of std::left, std::right, and std::internal.


C++ streams have three ways to format floating-point values:

- Fixed format – always displays a number, a decimal point, and a fraction part (i.e. it never uses scientific format such as 1.23e5, regardless of how big or small the number is)
- Scientific format – always uses scientific format such as 1.23e5
- General format – uses fixed format if the number isn't too big or small, otherwise uses scientific format. This is the default format.

To take control of floating-point formatting, use the std::fixed and std::scientific manipulators. std::fixed and std::scientific apply to all subsequent outputs.  For example:

    double pi = 3.14159265358979;
    std::cout << std::fixed << pi << std::endl;
    std::cout << std::scientific << pi << std::endl;

There is no manipulator called std::general. Rather, if you want to re-establish the general formatting, you must call the unsetf() function upon the stream object, to unset the internal bit-fields that represent fixed and scientific formatting:

    std::cout.unsetf(std::ios::fixed | std::ios::scientific);

This demonstration illustrates how to format floating-point values.



There are several manipulators that allow you to fine-tune exactly how you want your values to be formatted. We explore these manipulators in this topic. All manipulators discussed here apply for all subsequent values passed to the stream.

The std::showpos and std::noshowpos manipulators allow you to specify whether you want the + sign to be displayed alongside positive numbers. The default is for the + sign not to be displayed. Here's a simple example:

    int x, y, z;
    std::cout << std::showpos;
    std::cout << x << " " << y << " " << z << std::endl;
    std::cout << std::noshowpos;
    std::cout << x << " " << y << " " << z << std::endl;

The std::dec, std::oct, and std::hex manipulators allow you to specify whether numbers should be formatted in decimal, octal, or hexadecimal. The default is decimal. The std::showbase manipulator is also quite handy, because it causes the number base to be displayed alongside numbers (i.e. a leading 0 for octal numbers, and a leading 0x for hexadecimal numbers). The std::noshowbase manipulator stops the number base from being displayed. Here's a simple example:

    std::cout << std::showbase;
    std::cout << 64 << std::endl;
    std::cout << std::oct << 64 << std::endl;
    std::cout << std::hex << 64 << std::endl;
    std::cout << std::noshowbase;

The std::uppercase manipulator causes numbers to be formatted with uppercase letters where necessary (i.e. A-F in hex numbers, X in the 0X prefix, and E for scientific formatting). The std::nouppercase manipulator stops letters being displayed in uppercase. Here's a simple example:

    std::cout << std::hex;
    std::cout << 123456789 << std::endl;
    std::cout << std::uppercase   << 123456789 << std::endl;
    std::cout << std::nouppercase << 123456789 << std::endl;

This demonstration illustrates how to use the manipulators described in this topic.
