#include <iostream>

using namespace std;

int main()
{
  string response;
  cout << "Enter menu choice " << endl << "More" << endl << "Quit" << endl;
  cin >> response;
  while (response != "Quit")
  {
      // Code to execute if Quit is not entered

      // Prompt user again with menu choices until Quit is entered
      cout << "Enter menu choice " << endl << "More" << endl << "Quit" << endl;
      cin >> response;
      cout << "\t" << response << endl;
  }
}
