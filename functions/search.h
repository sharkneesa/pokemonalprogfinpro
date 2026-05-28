#pragma once

#include "sort.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

inline std::string toLowerStr(const std::string &str) {
  std::string result = str;
  for (char &c : result) {
    c = std::tolower(static_cast<unsigned char>(c));
  }
  return result;
}

void searchByName(const std::vector<Pokemon> &pokedex,
                  const std::string &query);
