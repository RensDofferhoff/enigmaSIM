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

static const std::map<RotorType, RotorData> rotorData =
{
{RotorType::TEST, {RotorType::TEST, Mapping(alphabet), {'A'}}}
};

static MappedScrambler ETW(alphabet);
static MappedScrambler UKW(alphabet);
static const std::list<RotorType> TestList = {RotorType::TEST};

#endif
