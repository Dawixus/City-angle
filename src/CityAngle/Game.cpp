#include "Game.h"

#include <format>
#include <iostream>
#include <string>
#include <utility>

#include "Circle.h"
#include "Vec2.h"

Game::Game(City central_city, std::vector<City> other_cities)
    : central_city(std::move(central_city)),
      other_cities(std::move(other_cities)) {

    for (const auto& city : this->other_cities) {
        angles.push_back(
            Vec2::bearing(this->central_city.coords, city.coords)
        );
    }
}

bool Game::ask_for_city(const std::string& city_name) const {
    return city_name == central_city.name;
}

void Game::Start() {
    Circle c;

    for (size_t i = 0; i < other_cities.size(); ++i) {
        const double angle = angles[i];
        const City& city = other_cities[i];

        const std::string city_name =
            std::format("{} ({})", city.name, city.country_name);

        c.add(angle, city_name);
    }

    c.draw();

    while (tries < 5) {
        std::string guess_city_name;

        std::cout << "Enter city name: ";
        std::getline(std::cin >> std::ws, guess_city_name);

        if (ask_for_city(guess_city_name)) {
            std::cout << "You win!" << std::endl;
            return;
        }

        ++tries;
    }

    std::cout << "You lost!" << std::endl;
}