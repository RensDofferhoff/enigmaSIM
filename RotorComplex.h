#ifndef ROTORCOMPLEX_H
#define ROTORCOMPLEX_H

#include <list>
#include "Scrambler.h"
#include "Rotor.h"
#include "MappedScrambler.h"


class RotorComplex : public Scrambler {
public:
    ~RotorComplex();
    RotorComplex(const std::list<RotorType>& rotorList, const std::string ringSettings,
         const std::string startPositions, Scrambler* entry, Scrambler* reflector);
    char scramble(const char input);
private:
    std::list<Rotor*> rotors;
    Scrambler* reflector;
    Scrambler* entry;
};

#endif
