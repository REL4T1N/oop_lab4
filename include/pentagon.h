#ifndef PENTAGON_H
#define PENTAGON_H

#include <iostream>
#include "./figure.h"
#include <cmath>


template<Scalar T>
class Pentagon : public Figure<T> {
public:
    Pentagon() : Figure<T>() {}
    Pentagon(const Point<T> &center, T radius) : Figure<T>(center, radius) {
        this->calculatePoints();
    }


protected:
    void calculatePoints() override {
        this->points.clear();
        for (int i = 0; i < 5; i++ ) {
            T angle = 2 * M_PI * i / 5;
            T x = this->center.x + this->radius * std::cos(angle);
            T y = this->center.y + this->radius * std::sin(angle);
            this->points.push_back(std::make_unique<Point<T>>(x, y));
        }
    }

    const char* getName() const override {
        return "Pentagon";
    }
};


#endif