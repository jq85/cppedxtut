#pragma once

/*
* It contains two pure virtual functions. The idea here is that you can freeze an
* object or unfreeze it.
*/
// Pure virtual class (akin to 'interface'), representing the "freezable" capability
class Freezable
{
public:
  virtual void freeze() = 0;
  virtual void unfreeze() = 0;
};
