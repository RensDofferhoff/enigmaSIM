#ifndef DATA_H
#define DATA_H

#include <string>
#include <map>
#include <list>
#include "RotorComplex.h"
#include "MappedScrambler.h"
#include "EnigmaMachine.h"

enum class RotorType {I, II, III, IV, V, VI, VII, VIII, TEST};

static const MappedScrambler ETW(Mapping("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
static const MappedScrambler UKW_B(Mapping("YRUHQSLDPXNGOKMIEBFZCWVJAT"));
static const MappedScrambler UKW_A(Mapping("EJMZALYXVBWFCRQUONTSPIKHGD"));


static const Rotor TEST({RotorType::TEST, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", {'Q'}});
static const Rotor I({RotorType::I, "EKMFLGDQVZNTOWYHXUSPAIBRCJ", {'Q'}});
static const Rotor II({RotorType::II, "AJDKSIRUXBLHWTMCQGZNPYFVOE", {'E'}});
static const Rotor III({RotorType::III, "BDFHJLCPRTXVZNYEIWGAKMUSQO", {'V'}});
static const Rotor IV({RotorType::IV, "ESOVPZJAYQUIRHXLNFTGKDCMWB", {'J'}});
static const Rotor V({RotorType::V, "VZBRGITYUPSDNHLXAWMJQOFECK", {'Z'}});
static const Rotor VI({RotorType::VI, "JPGVOUMFYQBENHZRDKASXLICTW", {'Z','M'}});
static const Rotor VII({RotorType::VII, "NZJHGRCXMYSWBOUFAIVLPEKQDT", {'Z','M'}});
static const Rotor VIII({RotorType::VIII, "FKQHTLXOCBJSPDZRAMEWNIUYGV", {'Z','M'}});


#endif
