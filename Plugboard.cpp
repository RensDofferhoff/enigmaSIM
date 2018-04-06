#include "Plugboard.h"
#include <string>
#include <sstream>

Plugboard::Plugboard(std::string pairString) {
    std::stringstream ss(pairString);
    std::string mapString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while(ss.good()) {
       std::string substr;
       getline(ss, substr, ',');
       if(!substr.empty())
            mapString[substr[0] - 'A'] = substr[1];
    }
    map = Mapping(mapString);
}

char Plugboard::scramble(const char input) {
    return map[input];
}
