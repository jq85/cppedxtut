#include <iostream>

using namespace std;

/**
 */
int main()
{
  struct coffeeBean
  {
    string name;
    string country;
    int strength;
  };

  coffeeBean myBean = { "Strata", "Columbia", 10 };
  coffeeBean newBean; 
  newBean.name = "Flora";
  newBean.country = "Mexico";
  newBean.strength = 9;
  cout << "Coffee bean " + newBean.name + " is from " + newBean.country << endl;
}
