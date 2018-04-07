#ifndef ROTORCOMPLEX_H
#define ROTORCOMPLEX_H

#include <list>
#include "Scrambler.h"
#include "Rotor.h"
#include "MappedScrambler.h"


class RotorComplex : public Scrambler {
public:
    ~RotorComplex(){delete reflector; delete entry;}
    RotorComplex(const std::list<Rotor>& rotorList, const std::string ringSettings,
         const std::string startPositions, const Scrambler* entry, const Scrambler* reflector);
    RotorComplex(const std::list<Rotor>& rotorList, const Scrambler* entry_, const Scrambler* reflector_)
    : rotors(rotorList), reflector(reflector_->clone()), entry(entry_->clone()) {}
    RotorComplex* clone() const { return new RotorComplex(*this); };

    char scramble(const char input);
    void setSettings(const std::string positions, const std::string ringSettings);
private:
    std::list<Rotor> rotors;
    Scrambler* reflector;
    Scrambler* entry;
};

#endif
