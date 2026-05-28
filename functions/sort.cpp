#include "sort.h"

using namespace std;

void sortAndDisplayByIndex(vector<Pokemon> &pokedex) {
  sort(pokedex.begin(), pokedex.end(), compareByIndex);

  for (const auto &p : pokedex) {
    cout << p.index << " " << p.pokemonName << " [" << p.type1;
    if (!p.type2.empty())
      cout << "/" << p.type2;
    cout << "]" << endl;
  }
}
