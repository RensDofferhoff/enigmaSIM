#include "Rotor.h"

char Rotor::scramble(const char input) {
    return rotorData.map[input + (position + ringSetting) % 'A'];
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
