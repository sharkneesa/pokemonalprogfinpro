#ifndef STRUCT_POKE
#define STRUCT_POKE
#include <string>

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

    int from;
    int to;
    string terrain;

};



#endif