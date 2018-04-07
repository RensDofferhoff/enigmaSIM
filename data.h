#ifndef DATA_H
#define DATA_H

#include <string>
#include <map>
#include <list>
#include "RotorComplex.h"
#include "MappedScrambler.h"
#include "EnigmaMachine.h"

enum class RotorType {I, II, III, TEST};

static const MappedScrambler ETW(Mapping("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
static const MappedScrambler UKW_B(Mapping("YRUHQSLDPXNGOKMIEBFZCWVJAT"));

static const Rotor TEST({RotorType::TEST, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", {'Q'}});
static const Rotor I({RotorType::I, "EKMFLGDQVZNTOWYHXUSPAIBRCJ", {'Q'}});
static const Rotor II({RotorType::II, "AJDKSIRUXBLHWTMCQGZNPYFVOE", {'E'}});
static const Rotor III({RotorType::III, "BDFHJLCPRTXVZNYEIWGAKMUSQO", {'V'}});


#endif
