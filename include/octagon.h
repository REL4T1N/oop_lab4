#ifndef OCTAGON_H
#define OCTAGON_H

#include <iostream>
#include <cmath>
#include "./figure.h"


template<Scalar T>
class Octagon : public Figure<T> {
public:
    Octagon() : Figure<T>() {}
    Octagon(const Point<T> &center, T radius) : Figure<T>(center, radius) {
        this->calculatePoints();
    }


protected:
    void calculatePoints() override {
        this->points.clear();
        for (int i = 0; i < 8; i++) {
            T angle = 2 * M_PI * i / 8;
            T x = this->center.x + this->radius * std::cos(angle);
            T y = this->center.y + this->radius * std::sin(angle);
            this->points.push_back(std::make_unique<Point<T>> (x, y));
        }
    }

    const char* getName() const override {
        return "Octagon";
    }
};


#endif