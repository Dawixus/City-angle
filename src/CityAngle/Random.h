#ifndef CITYANGLE_RANDOM_H
#define CITYANGLE_RANDOM_H

#include <random>

class Random {
    long seed;
    std::mt19937 generator;

public:
    explicit Random(long seed);

    int range(int min, int max);
};


#endif //CITYANGLE_RANDOM_H
