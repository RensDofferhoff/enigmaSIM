#ifndef ROTOR_H
#define ROTOR_H

#include "Mapping.h"

const enum Rotors {I, II, III}

class Rotor {
public:
    Rotor();

private:
    Mapping map;
    int position;
    int ringSetting;
};

#endif
