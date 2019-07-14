#include <iostream>
#include <string>

class point
{
public:
    int x, y;

    // Plus other members, as appropriate.
};


std::istream & operator >> (std::istream & is, point & p)
{
    is >> p.x >> p.y;
    // std::cout << p.x << " & " << p.y;
    return is;
}


std::ostream & operator << (std::ostream & os, const point & p)
{
    os << "[" << p.x << "," << p.y << "]";
    return os;
}


int main()
{
  point p1, p2;
  std::cout << "Please enter two points: ";
  std::cin >> p1 >> p2;

  std::cout
  << "Here are your points..." << std::endl
  << p1 << std::endl
  << p2 << std::endl;

  return 0;
}
