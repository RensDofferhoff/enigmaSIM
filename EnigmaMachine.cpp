#include "EnigmaMachine.h"

EngimaMachine::EnigmaMachine(std::list<RotorType>& rotorList, std::string ringSettings,
     std::string startPositions, Scrambler* entry, Scrambler* reflector, std::string plugboardString) :
     rotorComplex(rotorList, ringSettings, startPositions, entry, reflector), plugboard(plugboardString) {}
