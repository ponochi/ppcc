#pragma once

#include <string>

std::string &LeftTrim(std::string &str, std::string chars)
{
  str.erase(0, str.find_first_not_of(chars));

  return str;
}
