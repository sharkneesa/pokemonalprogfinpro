#include "sort.h"

using namespace std;

int partition(vector<Pokemon> &pokedex, int low, int high) {
  Pokemon pivot = pokedex[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (compareByIndex(pokedex[j], pivot)) {
      i++;
      Pokemon temp = pokedex[i];
      pokedex[i] = pokedex[j];
      pokedex[j] = temp;
    }
  }
  Pokemon temp = pokedex[i + 1];
  pokedex[i + 1] = pokedex[high];
  pokedex[high] = temp;
  return (i + 1);
}

void quickSort(vector<Pokemon> &pokedex, int low, int high) {
  if (low < high) {
    int pi = partition(pokedex, low, high);
    quickSort(pokedex, low, pi - 1);
    quickSort(pokedex, pi + 1, high);
  }
}

void sortAndDisplayByIndex(vector<Pokemon> &pokedex) {
  if (!pokedex.empty()) {
    quickSort(pokedex, 0, pokedex.size() - 1);
  }

  for (const auto &p : pokedex) {
    cout << p.index << " " << p.pokemonName << " [";
    for (size_t i = 0; i < p.types.size(); i++) {
      if (i > 0)
        cout << "/";
      cout << p.types[i];
    }
    cout << "]" << endl;
  }
}
