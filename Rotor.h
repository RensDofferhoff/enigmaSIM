#ifndef ROTOR_H
#define ROTOR_H

#include <string>
#include <list>
#include "Scrambler.h"
#include "Mapping.h"

enum class RotorType;

struct RotorData {
    const RotorType type;
    Mapping map;
    const std::list<char> turnover;
};

class Rotor : public Scrambler {
public:
    Rotor(const RotorData& data, const char startposition, const char ringSetting)
    : rotorData(data), position(startposition), ringSetting(ringSetting) {};
    char scramble(const char input) const;
    bool checkOnTurnover();
    void rotate();

private:
    RotorData rotorData;
    char position;
    char ringSetting;

    int calcPosition(const int offset);
};

#endif
