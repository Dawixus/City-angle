#ifndef CITYANGLE_CITY_H
#define CITYANGLE_CITY_H

#include "Vec2.h"
#include <string>

using namespace std;

class City {
    public:
        Vec2 coords;
        string name;
        string country_name;
        City(Vec2 coords, string name, string country_name);
};


#endif //CITYANGLE_CITY_H
