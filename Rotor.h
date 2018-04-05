#ifndef ROTOR_H
#define ROTOR_H

#include "Scrambler.h"
#include "Mapping.h"
#include "data.h"

class Rotor : public Scrambler {
public:
    Rotor(const RotorType type, const char startposition, const char ringSetting, const char turnover, const char notch); //TODO SETTINGS class
    char scramble(const char input);
private:
    Mapping map;
    char position;
    char ringSetting;
    char turnover;
    char notch;
};

#endif
