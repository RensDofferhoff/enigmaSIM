#ifndef DATA_H
#define DATA_H

#include <string>
#include <map>
#include <list>
#include "RotorComplex.h"
#include "MappedScrambler.h"

enum class RotorType {I, II, III, TEST};


static const std::string alphabetString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const std::string RotorI = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
static const std::string RotorII = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
static const std::string RotorIII = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

static const Mapping alphabet(alphabetString);
static const Mapping UKW_B_MAP("YRUHQSLDPXNGOKMIEBFZCWVJAT");

static const std::map<RotorType, RotorData> rotorData =
{
{RotorType::TEST, {RotorType::TEST, Mapping(alphabet), {'A'}}},
{RotorType::I, {RotorType::I, Mapping(alphabet), {'Q'}}},
{RotorType::II, {RotorType::II, Mapping(alphabet), {'E'}}},
{RotorType::III, {RotorType::III, Mapping(alphabet), {'V'}}}
};

static MappedScrambler UKW_TEST(alphabet);
static MappedScrambler ETW(alphabet);
static MappedScrambler UKW_B(UKW_B_MAP);
static const std::list<RotorType> EnigmaIList = {RotorType::III, RotorType::II, RotorType::I};

#endif
