#ifndef STRUCT_POKE
#define STRUCT_POKE
#include <string>
#include <vector>

using namespace std;

struct Pokemon{

    string pokemonName;
    string index;
    vector<string> types;  

};

struct Location{

    int locIndex;
    string locName;

};

struct Routes{

    string from;
    string to;
    string terrain;

};

struct JourneyStep {
    string fromLocation;
    string toLocation;
    string terrain;
    string pokemonUsed;
};


struct JourneyLog{

    string journeyIndex;
    string startLoc;
    string endLoc;
    vector<JourneyStep> steps;

};



#endif