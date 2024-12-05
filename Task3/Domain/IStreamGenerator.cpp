#include "IStreamGenerator.h"

IStreamGenerator::IStreamGenerator(std::istream& input) : input(input) {}

int IStreamGenerator::generate() {
    int value;
    input >> value;
    return value;
}


