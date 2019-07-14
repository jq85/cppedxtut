#include "Rectangle3.h"


int Rectangle3::get_area() const
{
  return _width * _height;
}


//WARNING: trying to make this const, will result in compiler ERROR
void Rectangle3::resize(int new_width, int new_height)
{
  _width = new_width;
  _height = new_height;
}


int Rectangle3::get_width() const
{
  return _width;
}


int Rectangle3::get_height() const
{
  return _height;
}
