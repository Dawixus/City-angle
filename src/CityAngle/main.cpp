#include <iostream>
#include <string>

#include "Circle.h"
#include "City.h"
#include "Date.h"
#include "FileReader.h"
#include "Random.h"
#include "Game.h"

int main() {
    const std::string FILE_NAME = "cities.json";
    const std::vector<City> cities = FileReader::read(FILE_NAME);

    tuple<int,int,int> date = Date::getDay();
    Random random(std::get<0>(date) + 100 * std::get<1>(date) + 10000 * std::get<2>(date));
    std::vector<City> chosen_cities;

    for (int i = 0; i < 5; i++) {
        int k = random.range(0, cities.size() - 1);
        chosen_cities.push_back(cities[k]);
    }

    City chosen_city = cities[random.range(0, cities.size() - 1)];
    cout << chosen_city.name << endl;

    Game game(chosen_city,chosen_cities);

    game.Start();

    return 0;
}