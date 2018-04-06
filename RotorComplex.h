#ifndef ROTORCOMPLEX_H
#define ROTORCOMPLEX_H

#include <list>
#include "Scrambler.h"
#include "Rotor.h"
#include "MappedScrambler.h"


class RotorComplex : public Scrambler {
public:
    ~RotorComplex();
    RotorComplex(std::list<RotorType>& rotorList, std::string ringSettings,
         std::string startPositions, Scrambler* entry, Scrambler* reflector);
    char scramble(const char input);
private:
    std::list<Rotor*> rotors;
    Scrambler* reflector;
    Scrambler* entry;
};

#endif
