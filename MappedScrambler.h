#ifndef MAPPEDSCRAMBLER_H
#define MAPPEDSCRAMBLER_H

#include "Scrambler.h"
#include "Mapping.h"


class MappedScrambler : public Scrambler {
public:
    MappedScrambler(const Mapping& map) : map(map) {};
    char scramble(const char input) {return map[input];};
private:
    Mapping map;
};

#endif
