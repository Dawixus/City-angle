#include "FileReader.h"

#include <fstream>
#include <nlohmann/json.hpp>

std::vector<City> FileReader::read(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filename);

    nlohmann::json data;
    file >> data;

    std::vector<City> cities;

    for (const auto& [continent, countries] : data.items()) {
        for (const auto& [country, cityList] : countries.items()) {
            for (const auto& city : cityList) {
                cities.emplace_back(
                    Vec2(city.at("latitude").get<double>(),city.at("longitude").get<double>()),
                    city.at("name").get<std::string>(),
                    country
                );
            }
        }
    }
    return cities;
}
