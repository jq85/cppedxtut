#include "Rectangle.h"
#include "RectangleWithConstructor.h"
#include "RectangleWithConstructor0.h"
#include "Rectangle2.h"

void f()
{
  // this won't work
  // Rectangle a_rectangle{3, 4};
  Rectangle a_rectangle{};
  Rectangle small_rectangle{};

  // declare and initialize 'the_area' variable with a value.
  // By calling the Object's public method
  int the_area_2{a_rectangle.get_area()};
  int the_area_3 = a_rectangle.get_area();

  // These won't work:
  // int the_width = small_rectangle._width;
  // int the_height = small_rectangle._height;
  // These work:
  int the_width = small_rectangle.get_width();
  int the_height = small_rectangle.get_height();
}

void f_rectangle_with_constructor()
{
  // still can initialize with the default values
  RectangleWithConstructor rectangle_b{};
  // or with given values, won't work because params are private, and the constructor does not help
  // RectangleWithConstructor rectangle_c{2, 3};

  // AND I can initialize it with the constructor
  // RectangleWithConstructor rectangle_d();//this won't work; The COMPILER thinks of it as of function declaration with name 'rectangle_d' and the return type 'RectangleWithConstructor'.
  RectangleWithConstructor rectangle_d;
  // and resize later
  rectangle_d.resize(2, 3);

  RectangleWithConstructor0 r0(3, 3);
}

/**
*
*/
void f2()
{
  Rectangle2 uninitialized;
  Rectangle2 value{};//use {} even if the compiler knows.
  Rectangle2 aggregate{4, 7};
  value.resize(3, 5);
  aggregate.resize(1, 2);

  int area_of_value = value.get_area();
  int area_of_aggregate = aggregate.get_area();
}

/**
*
*/
int main()
{
  f();
  f_rectangle_with_constructor();
  f2();
}
