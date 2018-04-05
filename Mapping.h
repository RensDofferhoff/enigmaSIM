#ifndef MAPPING_H
#define MAPPING_H

#include <string>

class Mapping {
public:
    Mapping(const std::string& map);
    char operator[](const char input);
private:
    char alphabetMap[26];
};

#endif
