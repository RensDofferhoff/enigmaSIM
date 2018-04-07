#ifndef MAPPING_H
#define MAPPING_H

#include <string>

class Mapping {
public:
    Mapping() : alphabetMap() {};
    Mapping(const std::string& map);
    Mapping(const std::string& map, const bool reverse);
    char operator[](const char input);
private:
    char alphabetMap[26];
};

#endif
