#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H

#include "RotorComplex.h"
#include "Plugboard.h"
#include <string>

class EngimaMachine {
public:
    EngimaMachine(std::list<RotorType>& rotorList, std::string ringSettings,
         std::string startPositions, Scrambler* entry, Scrambler* reflector, std::string plugboardString);

    std::string encrypt(std::string input);
private:
    Plugboard plugboard;
    RotorComplex rotorComplex;
};

#endif
