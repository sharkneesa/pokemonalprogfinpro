#include "search.h"

using namespace std;

// Find the pokemon (not case-sensitive)
void searchByName(const vector<Pokemon> &pokedex, const string &query) {
  string lowerQuery = toLowerStr(query);

  bool found = false;

  for (const Pokemon &p : pokedex) {
    if (toLowerStr(p.pokemonName).find(lowerQuery) != string::npos) {
      cout << p.index << " " << p.pokemonName << " [" << p.type1;
      if (!p.type2.empty()) {
        cout << "/" << p.type2;
      }
      cout << "]" << endl;
      found = true;
    }
  }

  if (!found) {
    cout << "No Pokemon found matching '" << query << "'" << endl;
  }
}
