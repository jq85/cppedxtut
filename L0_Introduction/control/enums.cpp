#include <iostream>

using namespace std;

int main()
{
  enum Days { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
  cout << "size of enum Days is " << sizeof(Days) << endl;
  Days day;
  day = Thursday;
  cout << "The value of day is " << day << endl;

  enum PayDay { Sun = 333, Mon, Tue, Wed, Thu, Fri, Sat };
  cout << "size of enum PayDay is " << sizeof(PayDay) << endl;
  PayDay payDay;
  payDay = Thu;
  cout << "The value of payDay is " << payDay << endl;

}
