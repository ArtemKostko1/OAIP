#pragma once
#include <vector>
#include <string>
#include "visitor.h"
#ifndef FILE_SERVICE
#define FILE_SERVICE

using namespace std;

vector<Visitor> readVisitorsFromFile();

void writeVisitorsToFile(const vector<Visitor>& visitors);

#endif