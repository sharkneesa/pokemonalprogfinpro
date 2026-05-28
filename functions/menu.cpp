#include "menu.h"
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void loadingScreen() {

  cout << "===============================\n";
  cout << "+      6 P O K È M O N 7      +\n";
  cout << "===============================\n";
  this_thread::sleep_for(chrono::seconds(1));
  cout << endl;
  this_thread::sleep_for(chrono::seconds(1));
  cout << "Initializing system...\n";
  this_thread::sleep_for(chrono::seconds(1));
  cout << "Catching Pokemon...\n";
  this_thread::sleep_for(chrono::seconds(1));
  cout << "Building Region Map...\n";
  this_thread::sleep_for(chrono::seconds(1));

  cout << endl;

  cout << "[--------------------] 0%\n";
  this_thread::sleep_for(chrono::milliseconds(250));
  cout << "[##------------------] 10%\n";
  this_thread::sleep_for(chrono::milliseconds(250));
  cout << "[#####---------------] 25%\n";
  this_thread::sleep_for(chrono::milliseconds(250));
  cout << "[########------------] 40%\n";
  this_thread::sleep_for(chrono::milliseconds(250));
  cout << "[##########----------] 50%\n";
  this_thread::sleep_for(chrono::milliseconds(250));
  cout << "[###############-----] 75%\n";
  this_thread::sleep_for(chrono::milliseconds(250));
  cout << "[##################--] 90%\n";
  this_thread::sleep_for(chrono::milliseconds(250));
  cout << "[####################] 100%\n";
  this_thread::sleep_for(chrono::seconds(1));

  cout << endl;

  cout << "LOADING SUCCESSFUL!\n";

  cout << endl;
  this_thread::sleep_for(chrono::seconds(1));

  cout << "WELCOME TRAINER!\n";
};

void mainMenuShown(){

  cout << endl;

  cout << "+---------------------------------+\n";
  cout << "|        6 P O K È M O N 7        |\n";
  cout << "|     KALOS TRAVEL NAVIGATION     |\n";
  cout << "+---------------------------------+\n";
  cout << "| [1] View Kalos Map              |\n";
  cout << "| [2] Pokédex                     |\n";
  cout << "| [3] Find Shortest Travel Route  |\n";
  cout << "| [4] Start Interactive Journey   |\n";
  cout << "| [5] Journey Log                 |\n";
  cout << "| [6] End Journey                 |\n";
  cout << "+---------------------------------+\n";

};

void pokedexMenuShow(){

   cout <<"+---------------------------------+\n";
  cout << "|        6 P O K È M O N 7        |\n";
  cout << "|          POKÈDEX MENU           |\n";
  cout << "+---------------------------------+\n";
  cout << "| [1] Search Pokémon by Name      |\n";
  cout << "| [2] Sort by Pokémon Index       |\n";
  cout << "| [3] Pokémon Type Tree           |\n";
  cout << "| [4] Back to Main Menu           |\n";
  cout << "+---------------------------------+\n";

};

