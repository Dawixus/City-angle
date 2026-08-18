#ifndef CITYANGLE_UTILS_H
#define CITYANGLE_UTILS_H

#include <cmath>
#include <ctime>
#include <random>
#include <tuple>

class Vec2 {
    constexpr static double HALF_TURN = 180.0;
    constexpr static double R = 6371.0;

public:
    double x;
    double y;

    Vec2(double x, double y) : x(x), y(y) {}

    static double distance(const Vec2& from, const Vec2& to) {
        auto lat1 = from.x * M_PI / HALF_TURN;
        auto lon1 = from.y * M_PI / HALF_TURN;
        auto lat2 = to.x * M_PI / HALF_TURN;
        auto lon2 = to.y * M_PI / HALF_TURN;

        auto dLat = lat2 - lat1;
        auto dLon = lon2 - lon1;

        auto a =
            std::sin(dLat / 2) * std::sin(dLat / 2) +
            std::cos(lat1) * std::cos(lat2) *
            std::sin(dLon / 2) * std::sin(dLon / 2);

        auto c = 2 * std::asin(std::sqrt(a));

        return R * c;
    }

    static double bearing(const Vec2& from, const Vec2& to) {
        auto lat1 = from.x * M_PI / HALF_TURN;
        auto lat2 = to.x * M_PI / HALF_TURN;
        auto dLon = (to.y - from.y) * M_PI / HALF_TURN;
        auto y = std::sin(dLon) * std::cos(lat2);

        auto x =std::cos(lat1) * std::sin(lat2) - std::sin(lat1) * std::cos(lat2) * std::cos(dLon);

        auto angle = std::atan2(y, x) * HALF_TURN / M_PI;

        if (angle < 0)
            angle += HALF_TURN * 2;

        return angle;
    }
};

class Date {
    constexpr static int EPOCH_START = 1900;

    public:
        static std::tuple<int, int, int> getDay() {
            std::time_t t = std::time(nullptr);
            std::tm* date = std::localtime(&t);
            int day = date->tm_mday;
            int month = date->tm_mon + 1;
            int year = date->tm_year + EPOCH_START;
            return {day, month, year};
        }
};

class Random {
    long seed;
    std::mt19937 generator;

public:
    explicit Random(const long seed): seed(seed), generator(seed) {}

    int range(const int min, const int max) {
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(generator);
    }
};

#endif //CITYANGLE_UTILS_H
