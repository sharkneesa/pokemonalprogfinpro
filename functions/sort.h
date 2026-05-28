#pragma once

#include "../models/structs.h"
#include <iostream>
#include <string>
#include <vector>

inline std::string formatTypes(const std::vector<std::string> &types) {
  std::string result;
  for (size_t i = 0; i < types.size(); i++) {
    if (i > 0)
      result += "/";
    result += types[i];
  }
  return result;
}

inline bool compareByIndex(const Pokemon &a, const Pokemon &b) {
  return a.index < b.index;
}

void sortAndDisplayByIndex(std::vector<Pokemon> &pokedex);
