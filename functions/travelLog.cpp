#include "travelLog.h"
#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;

vector<JourneyLog> travelLogTable[TABLE_SIZE];

int journeyCounter = 1;

int hashJourneyId(const string &journeyId) {
    int hashValue = 0;

    for (char c : journeyId) {
        hashValue += c;
    }

    return hashValue % TABLE_SIZE;
}

string generateJourneyId() {
    string id = "J";

    if (journeyCounter < 10) {
        id += "00";
    }
    else if (journeyCounter < 100) {
        id += "0";
    }

    id += to_string(journeyCounter);
    journeyCounter++;

    return id;
}

void saveJourneyLog(const string &startLocation,
                    const string &destinationLocation,
                    const vector<JourneyStep> &steps) {
    JourneyLog newLog;

    newLog.journeyIndex = generateJourneyId();
    newLog.startLoc = startLocation;
    newLog.endLoc = destinationLocation;
    newLog.steps = steps;

    int index = hashJourneyId(newLog.journeyIndex);

    travelLogTable[index].push_back(newLog);

    cout << "Journey log saved with ID: " << newLog.journeyIndex << endl;
}

void searchJourneyLogById(const string &journeyId) {
    int index = hashJourneyId(journeyId);

    for (const JourneyLog &log : travelLogTable[index]) {
        if (log.journeyIndex == journeyId) {
            cout << "Journey Log Found" << endl;
            cout << "Journey ID: " << log.journeyIndex << endl;
            cout << "Start: " << log.startLoc << endl;
            cout << "Destination: " << log.endLoc << endl;

            cout << "Journey Steps:" << endl;

            if (log.steps.empty()) {
                cout << "No steps recorded." << endl;
            }
            else {
                for (int i = 0; i < (int)log.steps.size(); i++) {
                    cout << i + 1 << ". "
                         << log.steps[i].fromLocation << " -> "
                         << log.steps[i].toLocation << endl;

                    cout << "Terrain: " << log.steps[i].terrain << endl;
                    cout << "Pokemon Used: " << log.steps[i].pokemonUsed << endl;
                }
            }

            return;
        }
    }

    cout << "Journey log with ID " << journeyId << " was not found." << endl;
}

void showAllJourneyLogs() {
    bool found = false;

    cout << "All Journey Logs:" << endl;

    for (int i = 0; i < TABLE_SIZE; i++) {
        for (const JourneyLog &log : travelLogTable[i]) {
            cout << log.journeyIndex << " | "
                 << log.startLoc << " -> "
                 << log.endLoc
                 << " | Steps: " << log.steps.size()
                 << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "No journey logs have been saved yet." << endl;
    }
}

void travelLogMenu() {
    int choice;

    do {
        cout << "Journey Log Menu" << endl;
        cout << "[1] Search Journey Log by ID" << endl;
        cout << "[2] Show All Journey Logs" << endl;
        cout << "[3] Back to Main Menu" << endl;
        cout << "Select Action: ";
        cin >> choice;

        if (choice == 1) {
            string journeyId;

            cout << "Enter Journey ID: ";
            cin >> journeyId;

            searchJourneyLogById(journeyId);
        }
        else if (choice == 2) {
            showAllJourneyLogs();
        }
        else if (choice == 3) {
            cout << "Returning to Main Menu..." << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;

    } while (choice != 3);
}