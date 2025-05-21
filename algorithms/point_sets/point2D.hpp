//Chloé Leyssens

#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>

/*
* Point2D class template for 2D points.
* Supports various operations such as addition, subtraction
* scalar multiplication, division, dot product, cross product,
* distance calculation, and angle calculation.
* Can be used with different numeric types (int, float, double).
*/
template<typename T>
class Point2D {
public:
    T x, y;

    // Constructors
    Point2D() : x(T()), y(T()) {}
    Point2D(T x, T y) : x(x), y(y) {}

    // Classical operations
    Point2D<T> operator+(const Point2D<T>& other) const {
        return Point2D<T>(x + other.x, y + other.y);
    }

    Point2D<T> operator-(const Point2D<T>& other) const {
        return Point2D<T>(x - other.x, y - other.y);
    }

    Point2D<T> operator*(T scalar) const {
        return Point2D<T>(x * scalar, y * scalar);
    }

    Point2D<T> operator/(T scalar) const {
        return Point2D<T>(x / scalar, y / scalar);
    }

    bool operator==(const Point2D<T>& other) const {
        return x == other.x && y == other.y;
    }

    // Dot product
    // >=0 if angle between vectors is <=90 degrees
    // <0 if angle between vectors is >90 degrees
    T dot(const Point2D<T>& other) const {
        return x * other.x + y * other.y;
    }

    // 2D-cross product
    // >=0 if angle is CCW
    // <0 if angle is CW
    T cross(const Point2D<T>& other) const {
        return x * other.y - y * other.x;
    }

    // Distance to another point
    double distanceTo(const Point2D<T>& other) const {
        double dx = static_cast<double>(x - other.x);
        double dy = static_cast<double>(y - other.y);
        return std::sqrt(dx * dx + dy * dy);
    }

    // Length of the vector 
    double magnitude() const {
        return std::sqrt(static_cast<double>(x * x + y * y));
    }

    // Angle with another vector
    // In radians
    double angleWith(const Point2D<T>& other) const {
        double dotProd = static_cast<double>(dot(other));
        double crossProd = static_cast<double>(cross(other));
        return std::atan2(crossProd, dotProd); 
    }

};

#endif
