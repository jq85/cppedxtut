#pragma once

class Rectangle_2 {
  int width, height;
public:
  Rectangle_2(int x, int y) : width(x), height(y) {}
  int area(void) { return width * height; }
};
