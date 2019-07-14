#pragma once
#include <string>

// Pure virtual class, representing the "loggable" capability

class loggable
{
public:
  virtual void log(const std::string &message) const = 0;
};
