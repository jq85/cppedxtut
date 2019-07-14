#include <string>

class Person
{
private:
  std::string name;

protected:
  int age;

public:
  Person();
  Person(const std::string &name, int age);
  virtual ~Person();//If a base class defines one or more virtual functions, then it should also define a virtual destructor.

  // Overrideable function.
  virtual void display() const;
};
