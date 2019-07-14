/*
http://www.cplusplus.com/doc/tutorial/classes/
*/
#include "Rectangle.h"
#include "Rectangle_2.h"
#include <iostream>

using namespace std;

int main()
{
  Rectangle *init_with_new = new Rectangle();

  cout << init_with_new->_width << endl;
  init_with_new->_width = 2;
  init_with_new->_height = 3;
  cout << init_with_new->_width << endl;


  Rectangle_2 obj(2, 3);
  Rectangle_2 *foo, *bar, *baz;
  foo = &obj;
  bar = new Rectangle_2(5, 6);
  baz = new Rectangle_2[2] { {2, 5}, {3, 6} };

  cout << "obj's area: " << obj.area() << '\n';
  cout << "*foo's area: " << foo->area() << '\n';
  cout << "*bar's area: " << bar->area() << '\n';
  cout << "baz[0]'s area:" << baz[0].area() << '\n';
  cout << "baz[1]'s area:" << baz[1].area() << '\n';
  delete bar;
  delete[] baz;

  return 0;
}
