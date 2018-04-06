#include "EnigmaMachine.h"

EnigmaMachine::EnigmaMachine(const std::list<RotorType>& rotorList, const std::string ringSettings,
     const std::string startPositions, const Scrambler* entry, const Scrambler* reflector, const std::string plugboardString)
 : rotorComplex(rotorList, ringSettings, startPositions, entry, reflector), plugboard(plugboardString) {}

std::string EnigmaMachine::process(std::string input) {
    std::string output;
    for(auto inputChar : input) {
        output += plugboard.scramble(rotorComplex.scramble(plugboard.scramble(inputChar)));
    }
    return output;
}
