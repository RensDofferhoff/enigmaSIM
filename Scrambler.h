#ifndef SCRAMBLER_H
#define SCRAMBLER_H

class Scrambler {
public:
    virtual ~Scrambler() {}
    virtual char scramble(const char input) = 0;
    virtual Scrambler* clone() const = 0;
};

#endif
