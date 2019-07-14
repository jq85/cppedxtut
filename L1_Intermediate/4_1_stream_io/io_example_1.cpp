#include <iostream>
#include <string>

int main()
{
  double unitPrice;
  int quantity;
  std::string s;

  std::cout << "What do you want? ";
  std::cin >> s;

  std::cout << "What is the unit price? ";
  std::cin >> unitPrice;

  std::cout << "How many do you want? ";
  std::cin >> quantity;

  std::cout << "Total cost of " << quantity << " " << s << " is " << unitPrice * quantity << " EUROS " << std::endl;

  return 0;
}
