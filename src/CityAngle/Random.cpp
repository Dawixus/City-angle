#include "Random.h"

Random::Random(long seed)
    : seed(seed), generator(seed) {
}

int Random::range(int min, int max) {
    std::uniform_int_distribution distribution(min, max);
    return distribution(generator);
}