# INTRODUCTION TO STRING STREAMS
=================================

Q&A: iostream:
Three stream objects used for input, output, and errors in the std namespace:
  - cin
  - cout
  - cerr

Q&A: Streams and Classes:
What must you do to have istream or ostream input or output object types?
  - Override the << and >> operators in your class.

Q&A: File Open Modes:
Which mode will cause the contents of an existing file to be overwritten?
  - ios_base::trunc

The standard C++ library defines a std::stringstream class that
allow you to read and write data to/from a string using the stream operators >> and <<.

std::stringstream class is defined in the <sstream> header file.
std::stringstream inherits from std::iostream, so it inherits all the capabilities from this class.

The following example shows how to write formatted data to a std::stringstream object, by using the << operator.
The code snippet writes a person's name, age, and salary to a std::stringstream object.
Notice we insert a space character between the fields, just like you might do if you were displaying the information on the console:

    #include <sstream>// For std::stringstream.

    std::stringstream stream;
    stream << "Jane" << " " << 42 << " " << 15000 << std::endl;

The following example shows how to read formatted data from a std::stringstream object, by using the >> operator.
The code snippet reads the person's name, age, and salary from the std::stringstream object we created earlier:

        #include <sstream>// For std::stringstream.
        #include <string> // For std::string.
        #include <iostream>   // For std::cout etc.
        …

        std::string name;
        int age;
        double salary;
        stream >> name >> age >> salary;

        std::cout
        << "Name: " << name << std::endl
        << "Age: " << age << std::endl
        << "Salary:" << salary << std::endl;



# SETTING AND GETTING THE CONTENT OF A STRING STREAM
=====================================================

GET / SET
You can set or get the content of a std::stringstream object, by calling the str() method.
There are two overloaded versions of this method:

    // Set the content for a string stream.
    void str(const string & s);
    // Get the content for s string stream.
    std::string str() const;

The following code snippet shows how to set and get the content of a string stream:

    // Create a stringstream object.
    std::stringstream stream;

    // Set the string content for a stringstream.
    stream.str("Jane 42 15000");

    // Get the content from a stringstream.
    std::cout << "Content of string stream: " << stream.str() << std::endl;

    // We can still use the stringstream as stream of formatted data.
    std::string name;
    int age;
    double salary;
    stream >> name >> age >> salary;

    std::cout
        << "Name: " << name << std::endl
        << "Age: " << age << std::endl
        << "Salary:" << salary << std::endl;



CREATING A STRING STREAM FROM AN EXISTING STRING
================================================

The std::stringstream constructor allows you to create a string stream object from an existing std::string object.
This can be useful in two scenarios:

  - Overwriting an existing string with new content.
  - Parsing an existing formatted string to extract values.

OVERRIDING STRINGS
The following code snippet illustrates the first scenario, where we create a std::stringstream object to overwrite an existing string with new content.
The existing string contains 20 asterisk characters initially, and we overwrite some of this content with a person's name (Jane), age (42), and salary (15000):

    // Create a stringstream object to write to an existing string.
    std::string str = "********************";
    std::stringstream stream(str);

    // Do some output.
    stream << "Jane" << " " << 42 << " " << 15000;

    // See the effect.
    std::cout << stream.str() << std::endl;

This code snippet displays the following output on the console
(note that the formatted output "Jane 42 15000" has overwritten the first 13 asterisks in the string, leaving 7 remaining asterisks at the end of the string):

    Jane 42 15000*******

PARSING STRINGS
The following code snippet illustrates the second scenario,
where we create a std::stringstream object to parse an existing formatted string to extract values.
The existing string contains the formatted data "Jane 42 15000", and we extracts the name, age, and salary:

    // Create a stringstream object to read from an existing string.
    std::string str = "Jane 42 15000";
    std::stringstream stream(str);

    // Read formatted data from stringstream.
    std::string name;
    int age;
    double salary;
    stream >> name >> age >> salary;

    std::cout
        << "Name: " << name << std::endl
        << "Age: " << age << std::endl
        << "Salary:" << salary << std::endl;

This code snippet displays the following output on the console:

    Name: Jane
    Age: 42
    Salary:15000



# WRITE-ONLY AND READ-ONLY STRING STREAMS
==========================================

The std::stringstream class allows you to read and write formatted data to a string.
If you want to perform write-only or read-only operations, you can use one of the following classes instead:

- std::ostringstream
    - Output characters to a string.
- std::istringstream
    - Input characters from a string.

The following example shows how to create and use std::ostringstream and std::istringstream objects:

    // Create an ostringstream object, which supports write-only operations.
    std::ostringstream stream1;

    stream1 << "Jane" << " " << 42 << " " << 15000 << std::endl;

    // Create an istringstream object, which supports read-only operations.
    std::istringstream stream2(stream1.str());

    // Read formatted data from istringstream.
    std::string name;
    int age;
    double salary;
    stream2 >> name >> age >> salary;

    std::cout
        << "Name: " << name << std::endl
        << "Age: " << age << std::endl
        << "Salary:" << salary << std::endl;



# WORKING WITH WIDE CHARACTERS
==============================

C++ has a standard type named wchar_t, which represents wide characters.
Wide characters are useful if you need to represent non-roman character sets.
C++ also defines a set of related classes and objects that allow you to work with wide characters in your code:

  - std::wstring represents a string of wide characters.
  - std::wistream, std::wostream, and std::wstream allow you to input and output wide characters.
    std::wcin and std::wcout are predefined instances of std::wistream and std::wostream respectively.
  - std::wistringstream, std::wostringstream, and std::wstringstream allow you to input and output wide characters to/from a string.

The following code snippet shows how to read and write wide-character strings from a string stream:

    std::wstringstream stream;

    stream << "Jane" << " " << 42 << " " << 15000 << std::endl;

    std::wstring formattedString = stream.str();
    std::wcout << formattedString;

    std::wstring name;
    int age;
    double salary;
    stream >> name >> age >> salary;

    std::wcout
        << "Name: " << name << std::endl
        << "Age: " << age << std::endl
        << "Salary:" << salary << std::endl;



# ADDITIONAL STRING STREAM OPERATIONS
=====================================

The string-stream classes inherit from more basic classes in the C++ stream library:

  - std::istringstream inherits from std::istream.
  - std::ostringstream inherits from std::ostream.
  - std::stringstream inherits from std::iostream, which in turn inherits from both std::istream and std::ostream.

This means you can use the capabilities defined in std::istream and std::ostream when working with string streams.
For example, the following demonstration shows how to read and write binary data to a string-stream object,
by using the read() and write() methods inherited from std::istream and std::ostream respectively.
