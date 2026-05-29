#include "constants/data.h"
#include "functions/dfs.h"
#include "functions/bfs.h"
#include "functions/mapGraph.h"
#include "functions/menu.h"
#include "functions/search.h"
#include "functions/sort.h"
#include "functions/tree.h"
#include "functions/travelLog.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {

  int choice;

  loadingScreen();
  
  do{

    mainMenuShown();

    cout << "Select Action: ";
    cin >> choice;
    cout << endl;

    switch(choice){

      case 1:

        showKalosMap();
        routeConnections();

      break;

      case 2:

        int choice2;
        pokedexMenuShow();

        do{

          cout << "Select Action: ";
          cin >> choice2;
          cout << endl;
          if(choice2==1){
      
            string query;
            cout << "Which Pokemon Would You Like to Search For: ";
            cin >> query;
            searchByName(pokemons, query);
          }
          else if(choice2==2){
            sortAndDisplayByIndex(pokemons);
          }

          else if(choice2==3){
            groupAndDisplayByType(pokemons);
          }

          else if(choice2==4){
            cout<< "Returning to Main Menu...\n";
          }

          else{
            cout << "Invalid Choice Try Again!\n";
          }

        }while (choice2!=4);


      break;

      case 3:

      bfsMenu();

      break;

      case 4:

        dfsMenu();

      break;

      case 5:

      travelLogMenu();

      break;


    }

  }while(choice!=6);
  


  return 0;
}