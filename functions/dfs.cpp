#include "dfs.h"
#include "../constants/data.h"
#include "travelLog.h"re

#include <iostream>
#include <iomanip>
#include <stack>
#include <set>
#include <vector>
#include <string>

using namespace std;

bool isTypeCompatibleWithTerrain(const string &type, const string &terrain) {
    if (terrain == "Land") {
        return type == "Normal" || type == "Ground" || type == "Fighting";
    }
    else if (terrain == "Forest") {
        return type == "Grass" || type == "Bug" || type == "Flying" || type == "Normal";
    }
    else if (terrain == "City") {
        return type == "Electric" || type == "Normal" || type == "Steel";
    }
    else if (terrain == "Water") {
        return type == "Water" || type == "Ice" || type == "Flying";
    }
    else if (terrain == "Frozen") {
        return type == "Ice" || type == "Water" || type == "Steel";
    }
    else if (terrain == "Rock") {
        return type == "Rock" || type == "Ground" || type == "Steel" || type == "Fighting";
    }
    else if (terrain == "Mountain") {
        return type == "Flying" || type == "Rock" || type == "Ground" || type == "Grass";
    }
    else if (terrain == "Ruins") {
        return type == "Ghost" || type == "Psychic" || type == "Dark" || type == "Fairy";
    }
    else if (terrain == "Sacred") {
        return type == "Fairy" || type == "Psychic" || type == "Ghost" || type == "Fighting";
    }

    return false;
}

bool canTraverse(const vector<string> &pokemonTypes, const string &routeTerrain) {
    for (const string &pt : pokemonTypes) {
        if (isTypeCompatibleWithTerrain(pt, routeTerrain)) {
            return true;
        }
    }

    return false;
}

set<string> accessibleTerrains(const vector<string> &pokemonTypes) {
    set<string> result;

    vector<string> allTerrains = {
        "Land", "Forest", "City", "Water", "Frozen",
        "Rock", "Mountain", "Ruins", "Sacred"
    };

    for (const string &terrain : allTerrains) {
        if (canTraverse(pokemonTypes, terrain)) {
            result.insert(terrain);
        }
    }

    return result;
}

int findLocationIndex(const string &locationName) {
    for (int i = 0; i < (int)locations.size(); i++) {
        if (locations[i].locName == locationName) {
            return i;
        }
    }

    return -1;
}

string getOtherLocation(const Routes &route, const string &currentLocation) {
    if (route.from == currentLocation) {
        return route.to;
    }

    return route.from;
}

vector<int> getConnectedRouteIndexes(const string &currentLocation) {
    vector<int> connectedRoutes;

    for (int i = 0; i < (int)routes.size(); i++) {
        if (routes[i].from == currentLocation || routes[i].to == currentLocation) {
            connectedRoutes.push_back(i);
        }
    }

    return connectedRoutes;
}

vector<int> getCompatiblePokemonIndexes(const Routes &route) {
    vector<int> compatiblePokemon;

    for (int i = 0; i < (int)pokemons.size(); i++) {
        if (canTraverse(pokemons[i].types, route.terrain)) {
            compatiblePokemon.push_back(i);
        }
    }

    return compatiblePokemon;
}

set<int> dfsExplore(int startId, const vector<string> &pokemonTypes) {
    int n = (int)locations.size();

    if (startId < 0 || startId >= n) {
        return {};
    }

    vector<bool> visited(n, false);
    set<int> reachable;
    stack<int> stk;

    stk.push(startId);
    visited[startId] = true;
    reachable.insert(startId);

    while (!stk.empty()) {
        int curr = stk.top();
        stk.pop();

        string currentLocation = locations[curr].locName;
        vector<int> connectedRoutes = getConnectedRouteIndexes(currentLocation);

        for (int routeIndex : connectedRoutes) {
            Routes route = routes[routeIndex];

            if (canTraverse(pokemonTypes, route.terrain)) {
                string nextLocation = getOtherLocation(route, currentLocation);
                int next = findLocationIndex(nextLocation);

                if (next != -1 && !visited[next]) {
                    visited[next] = true;
                    reachable.insert(next);
                    stk.push(next);
                }
            }
        }
    }

    return reachable;
}

void explainBlocked(int startId, const vector<string> &pokemonTypes) {
    int n = (int)locations.size();

    if (startId < 0 || startId >= n) {
        return;
    }

    vector<bool> visited(n, false);
    stack<int> stk;
    set<string> blocked;

    stk.push(startId);
    visited[startId] = true;

    while (!stk.empty()) {
        int curr = stk.top();
        stk.pop();

        string currentLocation = locations[curr].locName;
        vector<int> connectedRoutes = getConnectedRouteIndexes(currentLocation);

        for (int routeIndex : connectedRoutes) {
            Routes route = routes[routeIndex];
            string nextLocation = getOtherLocation(route, currentLocation);
            int next = findLocationIndex(nextLocation);

            if (next == -1) {
                continue;
            }

            if (!visited[next]) {
                if (canTraverse(pokemonTypes, route.terrain)) {
                    visited[next] = true;
                    stk.push(next);
                }
                else {
                    string label = currentLocation + " -> " + nextLocation + " [" + route.terrain + " Route]";
                    blocked.insert(label);
                }
            }
        }
    }

    if (!blocked.empty()) {
        cout << "\nBlocked routes:" << endl;

        for (const string &b : blocked) {
            cout << "x " << b << endl;
        }
    }
}

void dfsMenu() {
    vector<JourneyStep> journeySteps;

    int startId;
    int destinationId;

    cout << "DFS Interactive Journey Mode" << endl;

    cout << "\nKalos Locations:" << endl;

    for (int i = 0; i < (int)locations.size(); i++) {
        cout << "[" << locations[i].locIndex << "] " << locations[i].locName << endl;
    }

    cout << "\nChoose Starting Location ID: ";
    cin >> startId;

    cout << "Choose Destination Location ID: ";
    cin >> destinationId;

    int n = (int)locations.size();

    if (startId < 0 || startId >= n || destinationId < 0 || destinationId >= n) {
        cout << "Invalid location ID." << endl;
        return;
    }

    string currentLocation = locations[startId].locName;
    string destinationLocation = locations[destinationId].locName;

    cout << "\nJourney started." << endl;
    cout << "Start: " << currentLocation << endl;
    cout << "Destination: " << destinationLocation << endl;

    while (currentLocation != destinationLocation) {
        cout << "\nCurrent Location: " << currentLocation << endl;
        cout << "Destination: " << destinationLocation << endl;

        vector<int> connectedRoutes = getConnectedRouteIndexes(currentLocation);

        if (connectedRoutes.empty()) {
            cout << "No available routes from this location." << endl;
            break;
        }

        cout << "\nAvailable Routes:" << endl;

        for (int i = 0; i < (int)connectedRoutes.size(); i++) {
            int routeIndex = connectedRoutes[i];
            Routes route = routes[routeIndex];
            string nextLocation = getOtherLocation(route, currentLocation);

            cout << "[" << i + 1 << "] "
                 << currentLocation << " -> " << nextLocation
                 << " | Terrain: " << route.terrain << endl;

            vector<int> compatiblePokemon = getCompatiblePokemonIndexes(route);

            cout << "Compatible Pokemon: ";

            if (compatiblePokemon.empty()) {
                cout << "None";
            }
            else {
                for (int j = 0; j < (int)compatiblePokemon.size(); j++) {
                    if (j > 0) {
                        cout << ", ";
                    }

                    cout << pokemons[compatiblePokemon[j]].pokemonName;
                }
            }

            cout << endl;
        }

        cout << "\n[0] Cancel Journey" << endl;

        int routeChoice;
        cout << "Choose Route: ";
        cin >> routeChoice;

        if (routeChoice == 0) {
            cout << "Journey cancelled." << endl;
            return;
        }

        if (routeChoice < 1 || routeChoice > (int)connectedRoutes.size()) {
            cout << "Invalid route choice. Try again." << endl;
            continue;
        }

        int selectedRouteIndex = connectedRoutes[routeChoice - 1];
        Routes selectedRoute = routes[selectedRouteIndex];
        string nextLocation = getOtherLocation(selectedRoute, currentLocation);

        vector<int> compatiblePokemon = getCompatiblePokemonIndexes(selectedRoute);

        if (compatiblePokemon.empty()) {
            cout << "No Pokemon can traverse this route. Choose another route." << endl;
            continue;
        }

        cout << "\nChoose Pokemon for this route:" << endl;

        for (int i = 0; i < (int)compatiblePokemon.size(); i++) {
            int pokeIndex = compatiblePokemon[i];

            cout << "[" << i + 1 << "] "
                 << pokemons[pokeIndex].pokemonName << " "
                 << pokemons[pokeIndex].index << " [";

            for (int j = 0; j < (int)pokemons[pokeIndex].types.size(); j++) {
                if (j > 0) {
                    cout << "/";
                }

                cout << pokemons[pokeIndex].types[j];
            }

            cout << "]" << endl;
        }

        int pokemonChoice;
        cout << "Choose Pokemon: ";
        cin >> pokemonChoice;

        if (pokemonChoice < 1 || pokemonChoice > (int)compatiblePokemon.size()) {
            cout << "Invalid Pokemon choice. Try again." << endl;
            continue;
        }

        int chosenPokemonIndex = compatiblePokemon[pokemonChoice - 1];
        Pokemon chosen = pokemons[chosenPokemonIndex];

        cout << "\n" << chosen.pokemonName
             << " was used to travel from "
             << currentLocation << " to " << nextLocation << "." << endl;

        set<string> terrains = accessibleTerrains(chosen.types);

        cout << "Accessible terrains: ";

        bool first = true;

        for (const string &t : terrains) {
            if (!first) {
                cout << ", ";
            }

            cout << t;
            first = false;
        }

        cout << endl;

        int currentId = findLocationIndex(currentLocation);

        set<int> reachable = dfsExplore(currentId, chosen.types);

        cout << "\nReachable locations using " << chosen.pokemonName << ":" << endl;

        for (int id : reachable) {
            cout << "- " << locations[id].locName;

            if (id == currentId) {
                cout << " [CURRENT]";
            }

            cout << endl;
        }

        explainBlocked(currentId, chosen.types);

        journeySteps.push_back({
            currentLocation,
            nextLocation,
            selectedRoute.terrain,
            chosen.pokemonName
        });

        currentLocation = nextLocation;
    }

    if (currentLocation == destinationLocation) {
        cout << "\nDestination reached!" << endl;

        cout << "\nJourney Summary:" << endl;

        for (int i = 0; i < (int)journeySteps.size(); i++) {
            cout << i + 1 << ". "
                 << journeySteps[i].fromLocation << " -> "
                 << journeySteps[i].toLocation << endl;

            cout << "Terrain: " << journeySteps[i].terrain << endl;
            cout << "Pokemon Used: " << journeySteps[i].pokemonUsed << endl;

        }

        saveJourneyLog(locations[startId].locName, destinationLocation, journeySteps);
    }
}