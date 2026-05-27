#include <vector>
#include "data.h"

using namespace std;

vector<Pokemon>pokemons={

    {"Bibarel","#0400","Normal","Water"},
    {"Charizard","#0006","Fire","Flying"},
    {"Lapras","#0131","Ice","Water"},
    {"Greninja","#0658","Water","Dark"},
    {"Rotom","#0025","Electric","Ghost"},
    {"Chesnaught","#0652","Grass","Fighting"},
    {"Aurorus","#0699","Ice","Rock"},
    {"Pangoro","#0675","Fighting","Dark"},
    {"Garchomp","#0445","Ground","Dragon"},
    {"Altaria","#0334","Flying","Dragon"},
    {"Gengar","#0094","Poison","Ghost"},
    {"Hoopa","#0720","Psychic","Ghost"},
    {"Shedinja","#0292","Bug","Ghost"},
    {"Tyrantrum","#0697","Rock","Dragon"},
    {"Aggron","#0306","Steel","Rock"},
    {"Aegislash","#0681","Ghost","Steel"},
    {"Hydreigon","#0635","Dragon","Dark"},
    {"Diancie","#0719","Fairy","Rock"}

};

vector<Location>locations={

    {0,"Vaniville Tow"},
    {1,"Santalune Forest"},
    {2,"Santalune City"},
    {3,"Lumiose City"},
    {4,"Parfum Palace"},
    {5,"Glittering Cave"},
    {6,"Ambrette Coast"},
    {7,"Cyllage Cliff"},
    {8,"Geosenge Ruins"},
    {9,"Tower of Mastery"},
    {10,"Coumarine Harbor"},
    {11,"Frost Cavern"}

};

vector<Routes>route={

    {"Vaniville Town","Santalune Forest","Land"},
    {"Santalune Forest","Santalune City","Forest"},
    {"Santalune City","Lumiose City","City"},
    {"Lumiose City","Parfum Palace","Sacred"},
    {"Lumiose City","Coumarine Harbor","Water"},
    {"Coumarine Harbor","Frost Cavern","Frozen"},
    {"Frost Cavern","Ambrette Coast","Rock"},
    {"Glittering Cave","Cyllage Cliff","Mountain"},
    {"Cyllage Cliff","Geosenge Ruins","Ruins"},
    {"Geosenge Ruins","Tower of Mastery","Sacred"},
    {"Ambrette Coast","Coumarine Harbor","Water"},
    {"Santalune Forest","Glittering Cave","Forest"},
    {"Santalune City","Cyllage Cliff","Mountain"},
    {"Lumiose City","Geosenge Ruins","Ruins"}

};