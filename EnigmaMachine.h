#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H

#include "RotorComplex.h"
#include "Plugboard.h"
#include <string>

class EnigmaMachine {
public:
    EnigmaMachine(const std::list<Rotor>& rotorList, const std::string ringSettings,
         const std::string startPositions, Scrambler* entry, Scrambler* reflector, const std::string plugboardString);
    EnigmaMachine(const std::list<Rotor>& rotorList, Scrambler* entry, Scrambler* reflector);

    void setSettings(const std::string ringSettings, const std::string startPositions, const std::string plugboardString);

    std::string process(std::string input);
private:
    RotorComplex rotorComplex;
    Plugboard plugboard;
};

#endif
