#include "mapGraph.h"
#include <iostream>

using namespace std;

void showKalosMap(){

    cout << "       [ 6POKEMON7 SYSTEM ONLINE ]\n";
    cout << "------------------------------------------\n";
    cout << "> Region     : Kalos\n";
    cout << "> Professor  : Professor Sycamore\n";
    cout << "> Locations  : 12 Areas\n";
    cout << "> Routes     : 14 Routes\n";
    cout << "------------------------------------------\n";

    cout << "        [4] Parfum Palace\n";
    cout << "                 |\n";
    cout << "              Sacred\n";
    cout << "                 |\n";
    cout << "        [3] Lumiose City ---------------- Ruins ---------------- [8] Geosenge Ruins -------- Sacred -------- [9] Tower of Mastery\n";
    cout << "           |       \\                                                           |\n";
    cout << "           |        \\                                                          |\n";
    cout << "         City       Water                                                     Ruins\n";
    cout << "           |          \\                                                        |\n";
    cout << "           |           \\                                                       |\n";
    cout << "[0] Vaniville Town -- Land -- [1] Santalune Forest -- Forest -- [2] Santalune City\n";
    cout << "                         \\                                  \\                 |\n";
    cout << "                          \\                                  \\                |\n";
    cout << "                         Forest                            Mountain          Mountain\n";
    cout << "                            \\                                  \\              |\n";
    cout << "                             \\                                  \\             |\n";
    cout << "                         [6] Glittering Cave ---- Mountain ---- [7] Cyllage Cliff\n";
    cout << "                                  |\n";
    cout << "                                 Rock\n";
    cout << "                                  |\n";
    cout << "                         [11] Frost Cavern\n";
    cout << "                                  |\n";
    cout << "                                Frozen\n";
    cout << "                                  |\n";
    cout << "                         [10] Coumarine Harbor ---- Water ---- [5] Ambrette Coast\n";

};

void routeConnections(){

    cout << endl;

    cout << "--------------Route Terrain--------------\n";
    cout << endl;
    cout << "[0] Vaniville Town       <--> [1] Santalune Forest      | Land\n";
    cout << "[1] Santalune Forest     <--> [2] Santalune City        | Forest\n";
    cout << "[2] Santalune City       <--> [3] Lumiose City          | City\n";
    cout << "[3] Lumiose City         <--> [4] Parfum Palace         | Sacred\n";
    cout << "[3] Lumiose City         <--> [10] Coumarine Harbor     | Water\n";
    cout << "[10] Coumarine Harbor    <--> [11] Frost Cavern         | Frozen\n";
    cout << "[11] Frost Cavern        <--> [6] Glittering Cave       | Rock\n";
    cout << "[6] Glittering Cave      <--> [7] Cyllage Cliff         | Mountain\n";
    cout << "[7] Cyllage Cliff        <--> [8] Geosenge Ruins        | Ruins\n";
    cout << "[8] Geosenge Ruins       <--> [9] Tower of Mastery      | Sacred\n";
    cout << "[5] Ambrette Coast       <--> [10] Coumarine Harbor     | Water\n";
    cout << "[1] Santalune Forest     <--> [6] Glittering Cave       | Forest\n";
    cout << "[2] Santalune City       <--> [7] Cyllage Cliff         | Mountain\n";
    cout << "[3] Lumiose City         <--> [8] Geosenge Ruins        | Ruins\n";
    cout << endl;
    cout << "-----------------------------------------\n";

    cout << endl;

};

