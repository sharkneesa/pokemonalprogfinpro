#ifndef BFS_POKE
#define BFS_POKE

#include "../models/structs.h"
#include <string>
#include <vector>

using namespace std;

int findLocationIndexBFS(const string &locationName);

vector<int> getConnectedLocationIndexesBFS(int locationIndex);

string getRouteTerrainBetween(const string &fromLocation, const string &toLocation);

vector<string> bfsShortestPath(int startId, int endId);

void displayBfsPath(const vector<string> &path);

void printLocationListBFS();

void bfsMenu();

#endif