#include "cellar_helper.h"

//Maximum of chars is 10 !!! So longer number then 10, will be deformed !!!
//Precision is set to 1, so all number will be round to 0.1
string int_to_string(int value)
{
    //INT to char array
    char buffer[10];
    dtostrf(value, 5, 0, buffer);

    //BUFFER to c++ std::string
    string temp1 = string(buffer);
    find_and_replace(temp1, " ", "");
    // Serial.println(temp1.c_str());

    //BUFFER to c String
    // String temp11 = String(buffer);
    // temp11.replace(" ", "");
    // Serial.println(temp11);

    return temp1;
}

//Maximum of chars is 10 !!! So longer number then 10, will be deformed !!!
//Precision is set to 1, so all number will be round to 0.1
string float_to_string(float value)
{
   //FLOAT to char array
    char buffer[10];
    dtostrf(value, 5, 0, buffer);

    //BUFFER to c++ std::string
    string temp1 = string(buffer);
    find_and_replace(temp1, " ", "");
    // Serial.println(temp1.c_str());

    //BUFFER to c String
    // String temp11 = String(buffer);
    // temp11.replace(" ", "");
    // Serial.println(temp11);

    return temp1;
}

void find_and_replace(string &source, string const &find, string const &replace)
{
    for (string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}