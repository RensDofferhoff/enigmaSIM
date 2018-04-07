#ifndef ROTORCOMPLEX_H
#define ROTORCOMPLEX_H

#include <list>
#include "Scrambler.h"
#include "Rotor.h"
#include "MappedScrambler.h"


class RotorComplex : public Scrambler {
public:
    RotorComplex(const std::list<Rotor>& rotorList, const std::string ringSettings,
         const std::string startPositions, Scrambler* entry, Scrambler* reflector);
    RotorComplex(const std::list<Rotor>& rotorList, Scrambler* entry_, Scrambler* reflector_)
    : rotors(rotorList), reflector(reflector_), entry(entry_) {}

    char scramble(const char input);
    void setSettings(const std::string positions, const std::string ringSettings);
private:
    std::list<Rotor> rotors;
    Scrambler* reflector;
    Scrambler* entry;
};

#endif
