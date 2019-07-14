// #include "stdafx.h"
#include <iostream>
#include <iomanip>

void demoFieldWidth();
void demoJustification();
void demoFloatingPoiont();
void demoMisManipulators();

int main()
{
  // demoFieldWidth();
  // demoJustification();
  // demoFloatingPoiont();
  demoMisManipulators();
  return 0;
}

/*
*setw sets the minimum width but does not cause truncation.
*/
void demoFieldWidth()
{
  const char *message = "wibble";

  // Default field width is 0.
  std::cout << "[" << message << "]" << std::endl;

  // Set a field width.
  std::cout << "[" << std::setw(10) << message << "]" << std::endl;

  // The field width is the minimum field width - it doesn't cause truncation.
  std::cout << "[" << std::setw(4) << message << "]" << std::endl;
  std::cout << "[" << std::setw(6) << message << "]" << std::endl;
}


void demoJustification()
{
  std::cout << std::left << std::setw(10) << "hello" << "world" << std::endl;
  std::cout << std::right << std::setw(10) << "hello" << "world" << std::endl;

  const char *message1 = "hello";
  const char *message2 = "world";

  // Default justification.
  std::cout << "[" << std::setw(10) << message1 << "]" << std::endl;
  std::cout << "[" << std::setw(10) << message2 << "]" << std::endl << std::endl;

  // Left justification.
  std::cout << std::left;
  std::cout << "[" << std::setw(10) << message1 << "]" << std::endl;
  std::cout << "[" << std::setw(10) << message2 << "]" << std::endl << std::endl;

  // Right justification.
  std::cout << std::right;
  std::cout << "[" << std::setw(10) << message1 << "]" << std::endl;
  std::cout << "[" << std::setw(10) << message2 << "]" << std::endl << std::endl;

  // Internal justificaion.
  std::cout << "[" << std::setw(10) << -123.45 << "]" << std::endl;
  std::cout << "[" << std::setw(10) << -67.89 << "]" << std::endl;
  std::cout << std::internal;
  std::cout << "[" << std::setw(10) << -123.45 << "]" << std::endl;
  std::cout << "[" << std::setw(10) << -67.89 << "]" << std::endl << std::endl;

  // Reinstate the default (right) justification.
  std::cout << std::right;
}

void demoFloatingPoiont()
{
  double pi = 3.14159265358979;
  double s = 1.989E30;
  double n = 42.0;

  // Set the precision.
  std::cout << std::setprecision(4);//NUMBER OF DECIMAL DIGITS for any format.

  // Default (i.e. general) format.
  std::cout << pi << std::endl;
  std::cout << s << std::endl;
  std::cout << n << std::endl << std::endl;

  // Fixed format.
  std::cout << std::fixed;
  std::cout << pi << std::endl;
  std::cout << s << std::endl;
  std::cout << n << std::endl << std::endl;

  // Scientific format.
  std::cout << std::scientific;
  std::cout << pi << std::endl;
  std::cout << s << std::endl;
  std::cout << n << std::endl << std::endl;

  // Reinstate general (i.e. not fixed or scientific) format.
  std::cout.unsetf(std::ios::fixed | std::ios::scientific);
  std::cout << pi << std::endl;
  std::cout << s << std::endl;
  std::cout << n << std::endl << std::endl;

  std::cout << std::internal << std::setw(10) << -123.45 << std::endl;
  std::cout << std::fixed << pi << std::endl;
  std::cout << std::scientific << pi << std::endl;
}

void demoMisManipulators()
{
  int x = 3;
  int y = 4;
  int z = -5;

  // Showing/hiding + sign.
  std::cout << x << " " << y << " " << z << std::endl;
  std::cout << std::showpos;
  std::cout << x << " " << y << " " << z << std::endl;
  std::cout << std::noshowpos;
  std::cout << x << " " << y << " " << z << std::endl << std::endl;

  // Formatting numbers in different bases.
  std::cout << 64 << std::endl;
  std::cout << std::oct << 64 << std::endl;
  std::cout << std::hex << 64 << std::endl << std::endl;
  std::cout << std::dec;

  // Displaying a prefix to indicate the base.
  std::cout << std::showbase;
  std::cout << 64 << std::endl;
  std::cout << std::oct << 64 << std::endl;
  std::cout << std::hex << 64 << std::endl << std::endl;
  std::cout << std::noshowbase;

  // Displaying letters in uppercase within numbers.
  std::cout << std::hex;
  std::cout << 123456789 << std::endl;



  //
  std::cout.unsetf(std::ios::fixed | std::ios::scientific);

  std::cout << std::showpos;
  std::cout << x << " " << y << " " << z << std::endl;
  std::cout << std::noshowpos;
  std::cout << x << " " << y << " " << z << std::endl;

  std::cout << std::showbase;
  std::cout << 64 << std::endl;
  std::cout << std::oct << 64 << std::endl;
  std::cout << std::hex << 64 << std::endl;
  std::cout << std::noshowbase;

  std::cout << std::hex;
  std::cout << 123456789 << std::endl;
  std::cout << std::uppercase   << 123456789 << std::endl;
  std::cout << std::nouppercase << 123456789 << std::endl;
}
