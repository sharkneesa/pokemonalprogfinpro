#ifndef DFS_POKE
#define DFS_POKE

#include "../models/structs.h"
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isTypeCompatibleWithTerrain(const string &type, const string &terrain);

bool canTraverse(const vector<string> &pokemonTypes, const string &routeTerrain);

set<string> accessibleTerrains(const vector<string> &pokemonTypes);

int findLocationIndex(const string &locationName);

string getOtherLocation(const Routes &route, const string &currentLocation);

vector<int> getConnectedRouteIndexes(const string &currentLocation);

vector<int> getCompatiblePokemonIndexes(const Routes &route);

set<int> dfsExplore(int startId, const vector<string> &pokemonTypes);

void explainBlocked(int startId, const vector<string> &pokemonTypes);

void dfsMenu();

#endif