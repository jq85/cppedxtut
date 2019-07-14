#include <iostream>

using namespace std;

int main()
{
  string response;

  do
  {
       cout << "Enter menu choice " << endl << "More" << endl << "Quit" << endl;
       cin >> response;
       cout << "\t" << response << endl;
       // Process the data.

  } while (response != "Quit");
}
