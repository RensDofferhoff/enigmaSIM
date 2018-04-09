#include "EnigmaMachine.h"

EnigmaMachine::EnigmaMachine(const std::list<Rotor>& rotorList, const std::string ringSettings,
     const std::string startPositions, const Scrambler* entry, const Scrambler* reflector, const std::string plugboardString)
 : rotorComplex(rotorList, ringSettings, startPositions, entry, reflector), plugboard(plugboardString) {}

 EnigmaMachine::EnigmaMachine(const std::list<Rotor>& rotorList, const Scrambler* entry, const Scrambler* reflector)
  : rotorComplex(rotorList, entry, reflector), plugboard("") {}

  void EnigmaMachine::setSettings(const std::string startPositions, const std::string ringSettings,
       const std::string plugboardString) {
    plugboard = Plugboard(plugboardString);
    rotorComplex.setSettings(ringSettings, startPositions);
 }

std::string EnigmaMachine::process(std::string input) {
    std::string output;
    for(auto inputChar : input) {
        output += plugboard.scramble(rotorComplex.scramble(plugboard.scramble(inputChar)));
    }
    return output;
}
