# MUTABLE KEYWORD
==================

The mutable keyword is used to declare that a data member can be assigned a value and it can only be applied to non static and non const members.
An example usage would be if you have a const object but need to be able to modify one of its data members we can declare it mutable and then we are able to change its value.
Consider the following example:


  #include <iostream>
  #include <string>

  using namespace std;

  class myClass {

  public:
      myClass(std::string s = "")
      {
          str = s;
      }
      void print() const
      {
          cout << str << endl;
      }

      void change(std::string chgstr) const {
          str = chgstr;
      }

  private:
      mutable std::string str;
  };


  int main()
  {
      const myClass cc("Hello World !!!!");
      std::string mystring("The string has changed.");
      cc.change(mystring);
      cc.print();

      return 0;
  }


The object cc of type myClass created in the main function is declared const, meaning we cannot modify any of its members.
However, if we look at the private member string str we see that it is declared mutable,
meaning we can modify it hence when we call cc.change(string)
the private mutable string str is updated and we can see this when we print str to the standard output.
