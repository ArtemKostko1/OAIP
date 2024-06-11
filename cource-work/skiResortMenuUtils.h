#pragma once
#include <ctime>
#ifndef SKI_RESORT_MENU_UTILS
#define SKI_RESORT_MENU_UTILS

using namespace std;

//string checkDocumentNumber();

string fillingRentalKit();

int fillingRentalTime();

time_t checkTimeNow();

time_t checkRentalPeriodEnd(int& rentalTime, time_t& rentalPeriodStart);

void fillingNewVisitor();

void updateVisitor();

void deleteVisitor();

void displayVisitors();

#endif