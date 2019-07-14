#pragma once

class Rectangle2
{
private:
  int _width;
  int _height;

public:
  Rectangle2() : _width{1}, _height{1}
  { }

  Rectangle2(int initial_width, int initial_height) :
    _width{initial_width}, _height{initial_height}
  { }

  int get_width();
  int get_height();
  void resize(int new_width, int new_height);
  int get_area();
};
