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

// string generate_random_string(int max_length){
//     string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//     random_device rd;
//     mt19937 engine(rd());
//     uniform_int_distribution<> dist(0, possible_characters.size()-1);
//     string ret = "";
//     for(int i = 0; i < max_length; i++){
//         int random_index = dist(engine); //get index between 0 and possible_characters.size()-1
//         ret += possible_characters[random_index];
//     }
//     return ret;
// }

// string generate_random_string(int max_length)
// {
//     string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

//     random_device rd;
//     mt19937 generator(rd());

//     std::shuffle(str.begin(), str.end(), generator);

//     return str.substr(0, max_length); // assumes 32 < number of characters in str
// }

string generate_random_string(int max_length)
{
    int numBytes = 0;
    int i = 0;
    int j = 0;
    string letters[40] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
    string randString = "";
    for (i = 0; i < max_length; i++)
    {
        randString = randString + letters[random(0, 40)];
    }
    return randString;
}