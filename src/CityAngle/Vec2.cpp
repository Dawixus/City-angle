#include "Vec2.h"

#include <cmath>

Vec2::Vec2(double x, double y)
    : x(x), y(y) {
}

double Vec2::distance(const Vec2& from, const Vec2& to) {
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

double Vec2::bearing(const Vec2& from, const Vec2& to) {
    auto lat1 = from.x * M_PI / HALF_TURN;
    auto lat2 = to.x * M_PI / HALF_TURN;
    auto dLon = (to.y - from.y) * M_PI / HALF_TURN;

    auto y = std::sin(dLon) * std::cos(lat2);

    auto x =
        std::cos(lat1) * std::sin(lat2) -
        std::sin(lat1) * std::cos(lat2) * std::cos(dLon);

    auto angle = std::atan2(y, x) * HALF_TURN / M_PI;

    if (angle < 0)
        angle += HALF_TURN * 2;

    return angle;
}