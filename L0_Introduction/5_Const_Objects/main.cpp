#include "Rectangle2.h"
#include "Rectangle3.h"

void f1()
{
  int x = 1;
  const int y = 2;

  x = 10; // OK
  // y = 20; //WARNING: NOK, compilation will fail
}

void f2()
{
  Rectangle2 mutable_rectangle{3, 4};
  // const Rectangle2 immutable_rectangle{3, 4};
  // int area = immutable_rectangle.get_area();//WARNING: NOK, compilation will fail if Rectangle2 is const
}

void f3()
{
  Rectangle3 const rectangle3{3, 3};
  int area = rectangle3.get_area(); //WARNING: OK for const object only if the called function is const
}

int main()
{
  f1();
  f2();
  f3();
  return 0;
}
