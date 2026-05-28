#include "sort.h"

using namespace std;

void sortAndDisplayByIndex(vector<Pokemon> &pokedex) {
  sort(pokedex.begin(), pokedex.end(), compareByIndex);

  for (const auto &p : pokedex) {
    cout << p.index << " " << p.pokemonName << " [";
    for (size_t i = 0; i < p.types.size(); i++) {
      if (i > 0) cout << "/";
      cout << p.types[i];
    }
    cout << "]" << endl;
  }
}
