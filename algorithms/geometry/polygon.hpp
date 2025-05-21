#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <cmath>
#include "point2D.hpp"

/*
* Polygon class template for 2D polygons.
* Supports different numeric types (int, float, double) for coordinates of points
*/
template<typename T>
class Polygon {
private:
    std::vector<Point2D<T>> vertices;

public:
    Polygon() {}

    Polygon(const std::vector<Point2D<T>>& points) : vertices(points) {}

    void addVertex(const Point2D<T>& point) {
        vertices.push_back(point);
    }

    int size() const {
        return vertices.size();
    }

    /*
    * Calculate the area of the polygon using the shoelace formula
    * and determine if the polygon is clockwise or counter-clockwise.
    * Returns the area as a double and sets the clockwise flag to true (clockwise) or false (counter-clockwise).
    * Time complexity: O(n)
    */
    double calculateArea(bool& clockwise) const {
        double area = 0.0;
        int n = vertices.size();

        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            area += static_cast<double>(vertices[i].cross(vertices[j]));
        }

        if (area > 0) {
            clockwise = false;  // Counter-clockwise
        } else {
            clockwise = true;   // Clockwise
        }

        return std::fabs(area) / 2.0;
    }

    const std::vector<Point2D<T>>& getVertices() const {
        return vertices;
    }
    
    /*
    * Classify point relative to the polygon
    * Returns and int to describe the relative position
    * 0: on edge, 1: inside, -1: outside
    * Time complexity: O(n)
    */
    int inside_polygon(const Point2D<T>& p) const {
        int crossings = 0;
        int n = vertices.size();

        for (int i = 0; i < n; ++i) {
            Point2D<T> a = vertices[i];
            Point2D<T> b = vertices[(i + 1) % n];

            // Check if point is on the edge (colinear and within bounds)
            int cross = (b - a).cross(p - a);
            if (cross == 0 &&
                std::min(a.x, b.x) <= p.x && p.x <= std::max(a.x, b.x) &&
                std::min(a.y, b.y) <= p.y && p.y <= std::max(a.y, b.y)) {
                return 0;
            }

            // Ray-casting: check for edge crossing the horizontal ray
            if ((a.y > p.y) != (b.y > p.y)) {
                double xIntersect = a.x + static_cast<double>(b.x - a.x) * (p.y - a.y) / (b.y - a.y);
                if (xIntersect > p.x) {
                    crossings++;
                }
            }
        }

        return (crossings % 2 == 1) ? 1 : -1;
    }
};

#endif 
