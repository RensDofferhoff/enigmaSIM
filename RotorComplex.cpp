#include "RotorComplex.h"
#include "data.h"
#include <string>
#include <list>
#include <stdexcept>
#include <iostream>

RotorComplex::RotorComplex(const std::list<Rotor>& rotorList, const std::string ringSettings,
     const std::string startPositions, const Scrambler* entry_, const Scrambler* reflector_)
     : reflector(reflector_->clone()), entry(entry_->clone()) {
    int i = 0;
    if(ringSettings.size() != rotorList.size() || startPositions.size() != rotorList.size()){
        throw std::runtime_error("invalid ring-settings or startpositions");
    }
    for(auto& rotor : rotorList) {
        rotors.push_back(Rotor(rotor));
        ++i;
    }
}

void RotorComplex::setSettings(const std::string positions, const std::string ringSettings) {
    int i = 0;
    if(ringSettings.size() != rotors.size() || positions.size() != rotors.size()){
        throw std::runtime_error("invalid ring-settings or startpositions");
    }
    for(auto& rotor : rotors) {
        rotor.setSettings(ringSettings[i], positions[i]);
        ++i;
    }
}

char RotorComplex::scramble(const char input) {
    char output = entry->scramble(input);

    auto it = rotors.rbegin();
    bool turn = it->checkOnTurnover();
    it->rotate(); //right rotor always rotates
    ++it;
    while(turn && it != rotors.rend()) {
        turn = it->checkOnTurnover();
        it->rotate();
        ++it;
    }

    for(auto it = rotors.rbegin(); it != rotors.rend(); ++it) {
        output = it->scramble(output);
    }
    output = reflector->scramble(output);
    for(auto& rotor : rotors) {
        output = rotor.scramble(output);
    }
    return entry->scramble(output);
}
