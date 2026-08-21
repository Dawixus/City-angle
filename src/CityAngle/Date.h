#ifndef CITYANGLE_DATE_H
#define CITYANGLE_DATE_H

#include <tuple>

constexpr static int EPOCH_START = 1900;

class Date {
    public:
        static std::tuple<int, int, int> getDay();
};


#endif //CITYANGLE_DATE_H
