#include "Rotor.h"

char Rotor::scramble(const char input) {
    position = position + 1;
    if (position == 'Z' + 1) {
        position = 'A';//TODO callback function
    }
    return map[position];
}
