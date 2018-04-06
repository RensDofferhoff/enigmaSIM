#include <iostream>
#include "EnigmaMachine.h"
#include "data.h"


int main(int argc, char const *argv[]) {
    EnigmaMachine machine(TestList, "A", "A", &ETW, &UKW, "");
    std::string input;
    std::cin >> input;
    std::cout << "processed text:" << std::endl << machine.process(input) << std::endl;
    return 0;
}
