# READING AND WRITING FORMATTED TEXT DATA
==========================================

You can use file stream objects to read and write formatted text data in a file using the >> and << operators,
just like you can read and write formatted text data on the console.
For example, you might want to output a person's name (a string), age (an int), and height (a double).
Note the following points:

- When writing data using the << operator,
  you must ensure values are separated from each other,
  e.g. by outputting a space between the values.

- When reading data using the >> operator,
  you must know the order of tokens in the file.
  For example, if the next token is a double,
  then you must read it into a double variable.
  If you try to read the value into the wrong type of variable, an error will occur.

EOL, EOF
If you want to write several records,
the typical approach is to write a newline character at the end of each record.
When you read the data back in again, use a loop to iterate over the records;
the std::istream class (and hence the std::ifstream class)
has an eof() function that tells you when you've reached the end of the file.

The following code example shows how to write several lines of formatted text data to a file.
Each line contains the name, age, and height of a person.
We output a newline character after each record, to indicate where one record ends and the next begins.
Note that we don't output a newline character after the final record;
this is because we want the end-of-file marker to appear immediately after the final record,
to indicate there's no more data in the file:

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

If you run the code above, it will write the following contents to peopleFile.txt. Here, we've used the notation [space], [newline], and [eof] to indicate where space, newline, and end-of-file characters appear in the file:

John[space]42[space]1.67[newline]
Jane[space]41[space]1.54[newline]
Bill[space]35[space]1.82[eof]
