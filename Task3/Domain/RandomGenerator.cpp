#include "RandomGenerator.h"

random_generator::random_generator(int min, int max) {
    generator = std::mt19937(std::random_device{}());
    distribution = std::uniform_int_distribution<int>(min, max);
}

int random_generator::generate() {
    return distribution(generator);
}
