#include "Mapping.h"
#include <stdexcept>

Mapping::Mapping(const std::string& map) {
    if(map.length() != 26) {
        throw std::runtime_error("map not 26 long");
    }
    int i = 0;
    for(auto character : map) {
        alphabetMap[i] = character;
        ++i;
    }
}

char Mapping::operator[](const char input) {
    int index = input - 'A';
    if(index >= 0 && index <= 26) {
        return alphabetMap[index];
    }
    throw std::runtime_error("illegal input character");
}
