#include "Rotor.h"
#include <iostream>

Rotor::Rotor(const RotorData& data) : rotorData(data), map(Mapping(rotorData.map)),
 reverseMap(Mapping(rotorData.map, true)) ,position('A'), ringSetting('A') {}

char Rotor::scramble(const char input) {
    char result;
    if(!reverse)
        result = map[localNormalization(input)];
    else
        result = reverseMap[localNormalization(input)];
    reverse = !reverse;
    return globalNormalization(result);
}

bool Rotor::checkOnTurnover() {
    for(auto pos : rotorData.turnover) {
        if(pos == position)
            return true;
    }
    return false;
}

char Rotor::globalNormalization(char input) {
    int globalPosition = input - (position + ringSetting - 2 * 'A');
    if(globalPosition >= 'A') {
        return globalPosition;
    }
    else {
        return 'Z' - ('A'- globalPosition - 1);
    }
}

char Rotor::localNormalization(char input) {
    int localPosition = (input + position + ringSetting - 3 * 'A') % 26 + 'A';
    return localPosition;
}

void Rotor::rotate() {
    position = calcPosition(1);
}

int Rotor::calcPosition(const int offset) {
    return (position - 'A' + offset) % 26 + 'A';
}
