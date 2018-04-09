#include <iostream>
#include "EnigmaMachine.h"
#include "data.h"
#include <cctype>

void capitalString(std::string& input) {
    for(size_t i = 0; i < input.length(); ++i) {
        input[i] = toupper(input[i]);
    }
}

int main(int argc, char const *argv[]) {
    EnigmaMachine enigmaI({II,IV,V}, &ETW, &UKW_B);
    std::string input;
    std::cout << "Enter input to process:" << std::endl;
    std::cin >> input;
    capitalString(input);
    enigmaI.setSettings("BLA", "BUL", "AV,BS,CG,DL,FU,HZ,IN,KM,OW,RX");
    std::cout << "processed text:" << std::endl << enigmaI.process(input) << std::endl;
    return 0;
}
