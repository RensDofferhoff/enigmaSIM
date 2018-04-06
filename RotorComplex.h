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
         const std::string startPositions, const Scrambler* entry, const Scrambler* reflector);
    char scramble(const char input) const;
private:
    std::list<Rotor*> rotors;
    const Scrambler* reflector;
    const Scrambler* entry;
};

#endif
