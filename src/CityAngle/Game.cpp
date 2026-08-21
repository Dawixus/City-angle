#include "Game.h"

#include <format>
#include <iostream>
#include <ostream>

#include "Circle.h"
#include "Vec2.h"

Game::Game(City& central_city, std::vector<City>& other_cities)
    : central_city(std::move(central_city)),
      other_cities(std::move(other_cities)) {

    for (const auto& city : this->other_cities) {
        angles.push_back(Vec2::bearing(central_city.coords, city.coords)
        );
    }
}

bool Game::ask_for_city(const string &city_name) const {
    if (city_name == central_city.name) return true;
    return false;
}

void Game::Start() {
    Circle c;
    while (tries < 5) {
        for (size_t i = 0; i < other_cities.size(); ++i) {
            const double angle = angles[i];
            const City& city = other_cities[i];
            const std::string city_name = std::format("{} ({})", city.name, city.country_name);
            c.add(angle, city_name);
        }

        c.draw();
        std::string guess_city_name;
        std::cout << "Enter country name: ";
        std::cin >> guess_city_name;
        if (ask_for_city(guess_city_name)) {
            cout << "You win!" << endl;
            break;
        }
        tries++;
    }
    cout << "You lost!" << endl;
}