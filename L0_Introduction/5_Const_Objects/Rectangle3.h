#pragma once

class Rectangle3
{
private:
  int _width;
  int _height;

public:
  Rectangle3() : _width{1}, _height{1}
  { }

  Rectangle3(int initial_width, int initial_height) :
    _width{initial_width}, _height{initial_height}
  { }

  int get_width() const;
  int get_height() const;
  void resize(int new_width, int new_height);
  int get_area() const;
};
