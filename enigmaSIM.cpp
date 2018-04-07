#include <iostream>
#include "EnigmaMachine.h"
#include "data.h"


int main(int argc, char const *argv[]) {
    EnigmaMachine enigmaI({I,II,III}, &ETW, &UKW_B);
    enigmaI.setSettings("AAA", "AAA", "");
    std::string input;
    std::cout << "Enter input to process:" << std::endl;
    std::cin >> input;
    std::cout << "processed text:" << std::endl << enigmaI.process(input) << std::endl;
    return 0;
}
