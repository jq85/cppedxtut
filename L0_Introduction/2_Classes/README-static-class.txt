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

  But then the static keyword applies to the variable x, not to the class itself.
  What people call a static class is just an ordinary class whose members are all static, so you never actually need to create an instance of such a class in order to use its members.
  A well-known example of such a class is java.lang.Math.
  There are no such classes in the C++ standard library. Instead, grouping together related names without any form of per-object state is done using namespaces. That is, prefer this:

      namespace foo {
        int bar(int);
        constexpr int baz = 42;
      }

  over this:

      struct foo {
          static int bar(int);
          static constexpr int baz = 42;
      };

https://stackoverflow.com/questions/9321/how-do-you-create-a-static-class-in-c
  If you're looking for a way of applying the "static" keyword to a class,
  like you can in C# for example, then you won't be able to without using Managed C++.
*/
