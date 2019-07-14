#include <string>

class Person
{

private:
  std::string _firstName;
  std::string _lastName;
  int _age;

public:
  Person();
  Person(std::string firstName, std::string lastName);
  Person(std::string firstName, std::string lastName, int age);
  ~Person();

  //getters and setters
  void setFirstName(std::string firstName);
  std::string getFistName();

  void setLastName(std::string lastName);
  std::string getLastName();

  void setAge(int age);
  int getAge();

  void SayHello();
};
