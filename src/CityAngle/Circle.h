#ifndef CITYANGLE_CIRCLE_H
#define CITYANGLE_CIRCLE_H

#include <string>
#include <vector>

constexpr double FULL_CIRCLE = 360.0;
constexpr double HALF_CIRCLE = 180.0;
constexpr char CENTER_SYMBOL = 'O';
constexpr char EMPTY_SYMBOL = ' ';

class Circle {
private:
    struct Point {
        double angle;
        std::string text;
    };

    static constexpr double FULL_CIRCLE = 360.0;
    static constexpr double HALF_CIRCLE = 180.0;
    static constexpr double TERMINAL_Y_SCALE = 0.5;

    static constexpr char CENTER_SYMBOL = 'O';
    static constexpr char EMPTY_SYMBOL = ' ';

    int radius;
    std::vector<Point> points;

public:
    explicit Circle(int radius = 30);

    void add(double angle, const std::string& text);
    void clear();
    void draw() const;
};


#endif //CITYANGLE_CIRCLE_H
