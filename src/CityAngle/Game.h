//
// Created by davidkveton on 8/20/26.
//

#ifndef CITYANGLE_GAME_H
#define CITYANGLE_GAME_H

constexpr int MAX_TRIES = 7;

#include <vector>

#include "City.h"

class Game {
public:
    City central_city;
    std::vector<City> other_cities;
    std::vector<double> angles;
    int tries = 1;

    Game(City& central_city, std::vector<City>& other_cities);

    void Start() const;
};

#endif //CITYANGLE_GAME_H
