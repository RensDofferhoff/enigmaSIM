#ifndef SCRAMBLER_H
#define SCRAMBLER_H

class Scrambler {
public:
    virtual ~Scrambler() {}
    virtual char scramble(const char input) const = 0;
};

#endif
