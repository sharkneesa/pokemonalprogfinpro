#ifndef STRUCT_POKE
#define STRUCT_POKE
#include <string>
#include <vector>

using namespace std;

struct Pokemon{

    string pokemonName;
    string index;
    string type1;
    string type2;

};

struct Trainer{

    string name;
    string trainerID;
    string pokePartner;
    string location;

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

struct JourneyLog{

    string journeyIndex;
    string startLoc;
    string endLoc;
    vector<string> pokemonUsed;

};



#endif