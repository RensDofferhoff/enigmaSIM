#include "Rotor.h"

Rotor::Rotor(const RotorData& data) : rotorData(data), map(Mapping(rotorData.map)),
 reverseMap(Mapping(rotorData.map, true)) ,position('A'), ringSetting('A') {}

char Rotor::scramble(const char input) {
    char result;
    if(reverse)
        result = map[input + (position + ringSetting) % 'A'];
    else
        result = reverseMap[input + (position + ringSetting) % 'A'];
    reverse = !reverse;
    return result;
}

bool Rotor::checkOnTurnover() {
    for(auto pos : rotorData.turnover) {
        if(pos == position)
            return true;
    }
    return false;
}

void Rotor::rotate() {
    position = calcPosition(1);
}

int Rotor::calcPosition(const int offset) {
    return (position + offset) % 'A' + 'A';
}
