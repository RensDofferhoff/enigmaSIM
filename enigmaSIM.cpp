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
    EnigmaMachine enigmaI({I,II,II}, &ETW, &UKW_B);
    std::string input;
    std::string plugboardString;
    std::cout << "Enter plugboard settings:" << std::endl;
    std::cin >> plugboardString;
    std::cout << "Enter input to process:" << std::endl;
    std::cin >> input;
    capitalString(input);
    capitalString(plugboardString);
    enigmaI.setSettings("AAA", "AAA", plugboardString);
    std::cout << "processed text:" << std::endl << enigmaI.process(input) << std::endl;
    return 0;
}
