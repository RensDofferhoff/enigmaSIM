#ifndef DATA_H
#define DATA_H

#include <string>
#include <map>
#include "Rotor.h"

enum class RotorType {I, II, III};

const std::map<RotorType, RotorData> rotorData;

 const std::string RotorI = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
 const std::string RotorII = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
 const std::string RotorIII = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

#endif
