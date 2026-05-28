#include "search.h"

using namespace std;

// Find the pokemon (not case-sensitive)
void searchByName(const vector<Pokemon> &pokedex, const string &query) {
  string lowerQuery = toLowerStr(query);

  bool found = false;

  for (const Pokemon &p : pokedex) {
    if (toLowerStr(p.pokemonName).find(lowerQuery) != string::npos) {
      cout << p.index << " " << p.pokemonName << " [";
      for (size_t i = 0; i < p.types.size(); i++) {
        if (i > 0) cout << "/";
        cout << p.types[i];
      }
      cout << "]" << endl;
      found = true;
    }
  }

  if (!found) {
    cout << "No Pokemon found matching '" << query << "'" << endl;
  }
}
