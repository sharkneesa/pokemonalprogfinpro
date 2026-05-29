#ifndef TRAVEL_LOG_H
#define TRAVEL_LOG_H

#include "../models/structs.h"
#include <string>
#include <vector>

using namespace std;

int hashJourneyId(const string &journeyId);

string generateJourneyId();

void saveJourneyLog(const string &startLocation, const string &destinationLocation, const vector<JourneyStep> &steps);

void searchJourneyLogById(const string &journeyId);

void showAllJourneyLogs();

void travelLogMenu();

#endif