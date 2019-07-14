#include "Rectangle2.h"


int Rectangle2::get_area()
{
  return _width * _height;
}


void Rectangle2::resize(int new_width, int new_height)
{
  _width = new_width;
  _height = new_height;
}


int Rectangle2::get_width()
{
  return _width;
}


int Rectangle2::get_height()
{
  return _height;
}
