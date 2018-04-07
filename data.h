#ifndef DATA_H
#define DATA_H

#include <string>
#include <map>
#include <list>
#include "RotorComplex.h"
#include "MappedScrambler.h"

enum class RotorType {I, II, III, TEST};

static const MappedScrambler ETW(Mapping("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
static const MappedScrambler UKW_B(Mapping("YRUHQSLDPXNGOKMIEBFZCWVJAT"));

static const Rotor TEST({RotorType::TEST, Mapping("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), {'Q'}});
static const Rotor I({RotorType::I, Mapping("EKMFLGDQVZNTOWYHXUSPAIBRCJ"), {'Q'}});
static const Rotor II({RotorType::II, Mapping("AJDKSIRUXBLHWTMCQGZNPYFVOE"), {'E'}});
static const Rotor III({RotorType::III, Mapping("BDFHJLCPRTXVZNYEIWGAKMUSQO"), {'V'}});

#endif
