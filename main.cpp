#include "constants/data.h"
#include "functions/graph.h"
#include "functions/login.h"
#include "functions/mapGraph.h"
#include "functions/menu.h"
#include "functions/pokemon.h"
#include "functions/search.h"
#include "functions/sort.h"
#include "functions/tree.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {

  int choice;

  loadingScreen();
  mainMenuShown();
  
  do{

  cout << "Select Action: ";
  cin >> choice;
  cout << endl;

  switch(choice){

    case 1:

    break;

    case 2:

      int choice2;
      pokedexMenuShow();
      cout << "Select Action: ";
      cin >> choice2;
      cout << endl;
      if(choice2==1){
      
        string query;
        cout << "Which Pokemon Would You Like to Search For: \n";
        cin >> query;
        searchByName(pokemons, query);
      }
      else if(choice2==2){
        sortAndDisplayByIndex(pokemons);
      }

      else if(choice2==3){
        groupAndDisplayByType(pokemons);
      }

      else{
        cout << "Invalid Choice Try Again!\n";
      }

    break;

    case 3:

    break;

    case 4:

    break;

    case 5:

    break;


  }

  }while(choice!=6);
  


  return 0;
}