#include "IStreamGenerator.h"

i_stream_generator::i_stream_generator(std::istream& input) : input(input) {}

int i_stream_generator::generate() {
    int value;
    input >> value;
    return value;
}


