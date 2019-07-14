#pragma once

class RectangleWithConstructor
{
private:
  int _width;
  int _height;
public:
  // The constructor method
  // if the constructor requires values,
  // then it would be mandatory to pass values on the declaration
  // Rectangle(/*int initial_width, int initial_height*/): this->_width{}, this->_height{}
  RectangleWithConstructor() :
    _width{},
    _height{}
  {  }
  // Rectangle(int initial_width, int initial_height): this->_width{initial_width}, this->_height{initial_height}
  // {  }
  void resize(int new_width, int new_height)
  {
    this->_width = new_width;
    this->_height = new_height;
  }
};
