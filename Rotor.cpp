#include "Rotor.h"
#include <iostream>

Rotor::Rotor(const RotorData& data) : rotorData(data), map(Mapping(rotorData.map)),
 reverseMap(Mapping(rotorData.map, true)), position('A'), ringSetting('A') {}

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
    int globalPosition = input - (position - 'A') + (ringSetting - 'A');
    if(globalPosition >= 'A' && globalPosition <= 'Z') {
        return globalPosition;
    }
    else if(globalPosition < 'A') {
        return 'Z' - ('A'- globalPosition - 1);
    }
    else {
        return (globalPosition - 'Z') + 'A' - 1;
    }
}

char Rotor::localNormalization(char input) {
    int localPosition = input + (position - 'A') - (ringSetting - 'A');
    if(localPosition >= 'A' && localPosition <= 'Z') {
        return localPosition;
    }
    else if(localPosition < 'A') {
        return 'Z' - ('A'- localPosition - 1);
    }
    else {
        return (localPosition - 'Z') + 'A' - 1;
    }
}

void Rotor::rotate() {
    position = calcPosition(1);
}

int Rotor::calcPosition(const int offset) {
    return (position - 'A' + offset) % 26 + 'A';
}
