#pragma once

class RectangleWithConstructor0
{
private:
  int _width;
  int _height;
public:
  // The constructor method
  // if the constructor requires values,
  // then it would be mandatory to pass values on the declaration
  // Rectangle(/*int initial_width, int initial_height*/): this->_width{}, this->_height{}
  RectangleWithConstructor0( int initial_width, int initial_height ) :
    _width{initial_width},
    _height{initial_height}
  {  }
  // DELEGATING CONSTRUCTOR, USING OVERLOADING
  RectangleWithConstructor0( int initial_height ) : RectangleWithConstructor0( 11, initial_height )
  {  }
  // Rectangle(int initial_width, int initial_height): this->_width{initial_width}, this->_height{initial_height}
  // {  }
  void resize(int new_width, int new_height)
  {
    this->_width = new_width;
    this->_height = new_height;
  }
};
