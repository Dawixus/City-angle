#ifndef CITYANGLE_VEC2_H
#define CITYANGLE_VEC2_H

class Vec2 {
    constexpr static double HALF_TURN = 180.0;
    constexpr static double R = 6371.0;

public:
    double x;
    double y;

    Vec2(double x, double y);

    static double distance(const Vec2& from, const Vec2& to);
    static double bearing(const Vec2& from, const Vec2& to);
};

#endif //CITYANGLE_VEC2_H
