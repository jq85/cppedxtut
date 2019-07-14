#include <string>

class Person
{
private:
  int age;

protected:
  int phone;

public:
  const std::string first_name;
  const std::string last_name;
  const std::string race;

  Person();
  // Person(const std::string &name, int age);
  Person(const std::string &first_name, const std::string &last_name, std::string race, int age);

  virtual ~Person();//If a base class defines one or more virtual functions, then it should also define a virtual destructor.

  virtual void display();

  virtual void OutputIdentity() = 0;
  virtual void OutputAge();
};
