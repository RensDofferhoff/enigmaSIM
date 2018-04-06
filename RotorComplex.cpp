#include "RotorComplex.h"
#include "data.h"
#include <string>
#include <list>
#include <stdexcept>

RotorComplex::~RotorComplex() {
    for(auto rotor : rotors) {
        delete rotor;
    }
}

RotorComplex::RotorComplex(const std::list<RotorType>& rotorList, const std::string ringSettings,
     const std::string startPositions, const Scrambler* entry, const Scrambler* reflector) : reflector(reflector), entry(entry) {
    int i = 0;
    if(ringSettings.size() != rotorList.size() || startPositions.size() != rotorList.size()){
        throw std::runtime_error("invalid ring-settings or startpositions");
    }
    for(auto& rotor : rotorList) {
        rotors.push_back(new Rotor(rotorData.at(rotor), ringSettings[i], startPositions[i]));
        ++i;
    }
}

char RotorComplex::scramble(const char input) const {
    char output = entry->scramble(input);

    auto it = rotors.rbegin();
    (*it)->rotate(); //right rotor always rotates
    bool turn = (*it)->checkOnTurnover();
    ++it;
    while(turn && it != rotors.rend()) {
        turn = (*it)->checkOnTurnover();
        (*it)->rotate();
        ++it;
    }

    for(auto it = rotors.rbegin(); it != rotors.rend(); ++it) {
        output = (*it)->scramble(input);
    }
    output = reflector->scramble(input);
    for(auto& rotor : rotors) {
        output = rotor->scramble(input);
    }
    return entry->scramble(output);
}
