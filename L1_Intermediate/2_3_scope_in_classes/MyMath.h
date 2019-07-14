#pragma once

/*
http://www.cplusplus.com/forum/general/43943/
  class of static functions/vars
https://www.quora.com/What-is-a-static-class-in-c++
  Strictly speaking, there are no static classes in C++. You cannot do this:
  static class C {
    // ...
  };
  You can do this:
  static class C {
    // ...
  } x;
https://stackoverflow.com/questions/9321/how-do-you-create-a-static-class-in-c
  If you're looking for a way of applying the "static" keyword to a class,
  like you can in C# for example, then you won't be able to without using Managed C++.
*/
namespace MyMath
{
  // static class Math
  class Math
  {
  public:
    Math();
    ~Math();

    static int pow(int, int);
  };
};
