#include "bfs.h"
#include "../constants/data.h"

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int findLocationIndexBFS(const string &locationName) {
    for (int i = 0; i < (int)locations.size(); i++) {
        if (locations[i].locName == locationName) {
            return i;
        }
    }

    return -1;
}

vector<int> getConnectedLocationIndexesBFS(int locationIndex) {
    vector<int> connected;

    if (locationIndex < 0 || locationIndex >= (int)locations.size()) {
        return connected;
    }

    string currentLocation = locations[locationIndex].locName;

    for (int i = 0; i < (int)routes.size(); i++) {
        if (routes[i].from == currentLocation) {
            int nextIndex = findLocationIndexBFS(routes[i].to);

            if (nextIndex != -1) {
                connected.push_back(nextIndex);
            }
        }
        else if (routes[i].to == currentLocation) {
            int nextIndex = findLocationIndexBFS(routes[i].from);

            if (nextIndex != -1) {
                connected.push_back(nextIndex);
            }
        }
    }

    return connected;
}

string getRouteTerrainBetween(const string &fromLocation, const string &toLocation) {
    for (const Routes &route : routes) {
        if ((route.from == fromLocation && route.to == toLocation) ||
            (route.from == toLocation && route.to == fromLocation)) {
            return route.terrain;
        }
    }

    return "Unknown";
}

vector<string> bfsShortestPath(int startId, int endId) {
    int n = (int)locations.size();

    if (startId < 0 || startId >= n) {
        return {};
    }

    if (endId < 0 || endId >= n) {
        return {};
    }

    if (startId == endId) {
        return {locations[startId].locName};
    }

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;

    q.push(startId);
    visited[startId] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        vector<int> connectedLocations = getConnectedLocationIndexesBFS(current);

        for (int next : connectedLocations) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = current;

                if (next == endId) {
                    vector<string> path;

                    for (int node = endId; node != -1; node = parent[node]) {
                        path.push_back(locations[node].locName);
                    }

                    reverse(path.begin(), path.end());
                    return path;
                }

                q.push(next);
            }
        }
    }

    return {};
}

void displayBfsPath(const vector<string> &path) {
    if (path.empty()) {
        cout << "No path found between these locations." << endl;
        return;
    }

    int stops = (int)path.size() - 1;

    cout << "Shortest path found." << endl;
    cout << "Total route(s): " << stops << endl;

    for (int i = 0; i < (int)path.size(); i++) {
        if (i == 0) {
            cout << "[START] " << path[i] << endl;
        }
        else {
            string terrain = getRouteTerrainBetween(path[i - 1], path[i]);

            cout << "   | via " << terrain << " Route" << endl;

            if (i == (int)path.size() - 1) {
                cout << "[END]   " << path[i] << endl;
            }
            else {
                cout << "   +--   " << path[i] << endl;
            }
        }
    }
}

void printLocationListBFS() {
    cout << "Kalos Locations:" << endl;

    for (int i = 0; i < (int)locations.size(); i++) {
        cout << "[" << locations[i].locIndex << "] "
             << locations[i].locName << endl;
    }
}

void bfsMenu() {
    int startId;
    int endId;

    cout << "BFS Shortest Travel Route" << endl;

    cout << "Tip: View the Kalos Map first to check each location ID." << endl;

    printLocationListBFS();

    cout << "Enter Starting Location ID: ";
    cin >> startId;

    cout << "Enter Destination Location ID: ";
    cin >> endId;

    int n = (int)locations.size();

    if (startId < 0 || startId >= n || endId < 0 || endId >= n) {
        cout << "Invalid location ID. Please enter a number between 0 and "
             << n - 1 << "." << endl;
        return;
    }

    cout << "Searching route from "
         << locations[startId].locName
         << " to "
         << locations[endId].locName
         << endl;

    vector<string> path = bfsShortestPath(startId, endId);

    displayBfsPath(path);
}