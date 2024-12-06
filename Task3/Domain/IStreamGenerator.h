#pragma once
#pragma once
#include "Generator.h"
#include <iostream>

class i_stream_generator : public Generator {
private:
    std::istream& input;

public:
    i_stream_generator(std::istream& input = std::cin);
    int generate() override;
};


