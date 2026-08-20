#include "Circle.h"

#include <algorithm>
#include <cmath>
#include <iostream>

Circle::Circle(int radius)
    : radius(radius) {
}

void Circle::add(double angle, const std::string& text) {
    angle = std::fmod(angle, FULL_CIRCLE);

    if (angle < 0)
        angle += FULL_CIRCLE;

    points.push_back({angle, text});
}

void Circle::clear() {
    points.clear();
}

void Circle::draw() const {
    const int size = radius * 2 + 1;
    const int center = radius;

    std::vector<std::string> output(
        size,
        std::string(size, EMPTY_SYMBOL)
    );

    output[center][center] = CENTER_SYMBOL;

    for (const auto& point : points) {
        const double rad = point.angle * M_PI / HALF_CIRCLE;

        const int x = static_cast<int>(
            std::round(
                center + radius * std::cos(rad)
            )
        );

        const int y = static_cast<int>(
            std::round(
                center - radius * std::sin(rad) * TERMINAL_Y_SCALE
            )
        );

        int startX =x - static_cast<int>(point.text.length()) / 2;

        startX = std::max(0, startX);

        if (startX + point.text.length() >= size)
            startX = size - point.text.length() - 1;

        if (y < 0 || y >= size)
            continue;

        for (int i = 0; i < point.text.length(); ++i) {
            const int xPos = startX + i;

            if (xPos >= 0 && xPos < size)
                output[y][xPos] = point.text[i];
        }
    }

    for (const auto& line : output)
        std::cout << line << '\n';
}