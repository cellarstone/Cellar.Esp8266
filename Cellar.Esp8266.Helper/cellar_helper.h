#ifndef CELLARHELPER_H
#define CELLARHELPER_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//External libraries
#include <string>

using namespace std;

string int_to_string(int value);
string float_to_string(float value);
void find_and_replace(string &source, string const &find, string const &replace);

#endif