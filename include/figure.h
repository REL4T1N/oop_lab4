#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include "./point.h"
#include <istream>
#include <ostream>
#include <vector>
#include <memory>

template<Scalar T>
class Figure {
protected:
    Point<T> center;
    T radius;
    std::vector<std::unique_ptr<Point<T>>> points;

    virtual void calculatePoints() = 0;
    virtual const char* getName() const = 0;

public:
    Figure() : center(Point<T>{}), radius(T{}) {}
    Figure(const Point<T> &center, T radius) : center(center), radius(radius) {}

    virtual ~Figure() = default;

    virtual double area() const;
    virtual void print(std::ostream &os) const;
    virtual void read(std::istream &is);

    // гетеры
    Point<T> getCenter() const {return center;}
    T getRadius() const {return radius;}

    virtual operator double() const;
    virtual bool operator==(const Figure<T> &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Figure<T> &f) {
        f.print(os);
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Figure<T> &f) {
        f.read(is);
        return is;
    }  
};


template<Scalar T>
double Figure<T>::area() const {
    if (points.size() < 5) return 0.0;
    double area = 0.0;
    for (size_t i = 0; i < points.size(); i++) {
        size_t j = (i + 1) % points.size();
        area += points[i]->x * points[j]->y - points[j]->x * points[i]->y;
    }
    return std::abs(area) / 2.0;
}


template<Scalar T>
void Figure<T>::print(std::ostream &os) const {
    os << getName() << "[Center: " << center << ", Radius: " << radius << "] Points: ";
    for (const auto &point : points) {
        os << *point << " ";
    }
}


template<Scalar T>
void Figure<T>::read(std::istream &is) {
    is >> center.x >> center.y >> radius;
    calculatePoints();
}


template<Scalar T>
Figure<T>::operator double() const {
    return area();
}


template<Scalar T>
bool Figure<T>::operator==(const Figure<T> &other) const {
    return (center == other.center) && (radius == other.radius) && (points.size() == other.points.size());
}


#endif