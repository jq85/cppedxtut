#pragma once

class Rectangle
{
private:
  int _width;
  int _height;
public:

    int get_area()
    {
      return this->_width * this->_height;
    }
    int get_width() { return this->_width; }
    int get_height() { return this->_height; }
    void resize(int new_width, int new_height)
    {
      this->_width = new_width;
      this->_height = new_height;
    }
};
