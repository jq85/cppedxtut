#include <fstream>
#include <iostream>
#include <sstream>
#include "tempStat.h"


int main()
{
  std::ofstream ofile;
  // std::ifstream ifile;

  // 1. check the current running total.
  // checking the value of the most recent total.
  // This will ensure that you have an accurate total, even if you run your program multiple times.
  tempStat ts{"John", 22.0};
  // NOTE: std::ios_base::ate position the cursor at the end of the text
  // whereas std::ios_base_app appends text (with a write operation) at the end
  std::fstream file1("donation_total.txt", std::ios_base::app);
  double last_donation = ts.read_last_donation_from_file(file1);
  std::cout << "last donation is " << last_donation << std::endl;

  // NOTE: Which is the correct way to extract a donation amount from a string with the format "[Name] [Amount]"?
  // stream >> name >> amount;

  // 2. Your program will accept user-entered "donations" in the format "<name> <donation_amount>" from the console.
  // For example: "Tom 25"
  std::cout << "Enter name and donation amount: ";
  std::cin >> ts;
  std::cout << ts.name << " " << ts.donation_amount << std::endl;


  file1.close();
  // 3. It will then extract the donation amount, convert it to an integer amount,
  // then add that donation to a running total.
  double total = ts.add_donation(ts.donation_amount);

  // 4. Every time that the running total is updated, append the new total to your donation_total.txt.
  ts.append_new_total_to_file(/*ofile*/);

  return 0;
}
