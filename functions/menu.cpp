#include <iostream>
#include "menu.h"
#include <thread>
#include <chrono>

using namespace std;

void loadingScreen(){

    cout<< "===============================\n";
    cout<< "+      6 P O K E M O N 7      +\n";
    cout<< "===============================\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout<< endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<< "Initializing system...\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout<< "Catching Pokemon...\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout<< "Building Region Map...\n";
    this_thread::sleep_for(chrono::seconds(1));
  
    cout<< "[--------------------] 0%\n";
    this_thread::sleep_for(chrono::milliseconds(250));
    cout<< "[##------------------] 10%\n";
    this_thread::sleep_for(chrono::milliseconds(250));
    cout<< "[#####---------------] 25%\n";
    this_thread::sleep_for(chrono::milliseconds(250));
    cout<< "[########------------] 40%\n";
    this_thread::sleep_for(chrono::milliseconds(250));
    cout<< "[##########----------] 50%\n";
    this_thread::sleep_for(chrono::milliseconds(250));
    cout<< "[###############-----] 75%\n";
    this_thread::sleep_for(chrono::milliseconds(250));
    cout<< "[##################--] 90%\n";
    this_thread::sleep_for(chrono::milliseconds(250));
    cout<< "[####################] 100%\n";
    this_thread::sleep_for(chrono::seconds(1));

    cout<< "LOADING SUCCESSFUL!\n";


};