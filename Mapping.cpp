#include "Mapping.h"
#include <stdexcept>
#include <iostream>

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

Mapping::Mapping(const std::string& map, const bool reverse) {
    std::string base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    if(!reverse)
        Mapping(map);
    else {
        if(map.length() != 26) {
            throw std::runtime_error("map not 26 long");
        }
        for(char character : map) {
            alphabetMap[character % 'A'] = base[i];
            ++i;
        }
    }
}


char Mapping::operator[](const char input) {
    int index = input % 'A';
    if(index >= 0 && index <= 25) {
        std::cout << alphabetMap[index] << std::endl;
        return alphabetMap[index];
    }
    throw std::runtime_error("illegal input character");
}
