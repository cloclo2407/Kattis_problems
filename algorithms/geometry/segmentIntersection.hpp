//Chloé Leyssens

#ifndef SEGMENT_INTERSECTION_HPP
#define SEGMENT_INTERSECTION_HPP

#include <vector>
#include <algorithm>
#include "point2D.hpp"

using namespace std;

/*
* Check if point p is on segment ab
* Returns true if p is on segment ab, false otherwise
* Complexity: O(1)
*/
template <typename T>
bool onSegment(const Point2D<T>& a, const Point2D<T>& b, const Point2D<T>& p) {
    // Cross product to check colinearity
    auto cross = (b - a).cross(p - a);
    if (cross != 0) return false;
    // Bounding check
    return min(a.x, b.x) <= p.x && p.x <= std::max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= std::max(a.y, b.y);
}

/*
* Check orientation of the triplet (a, b, c)
* Returns 0 if colinear, 1 if clockwise, -1 if counterclockwise
* Complexity: O(1)
*/
template <typename T>
int orientation(const Point2D<T>& a, const Point2D<T>& b, const Point2D<T>& c) {
    auto val = (b - a).cross(c - a);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

/*
* Helper function to compute the intersection point of two lines
* Called only if segments are not parallel
* Returns true if lines intersect, false otherwise
* Sets x and y to the intersection point if they intersect
* Complexity: O(1)
*/
template <typename T>
bool lineIntersection(const Point2D<T>& a, const Point2D<T>& b,
                      const Point2D<T>& c, const Point2D<T>& d,
                      double& x, double& y) {
    long long A1 = b.y - a.y;
    long long B1 = a.x - b.x;
    long long C1 = A1 * a.x + B1 * a.y;

    long long A2 = d.y - c.y;
    long long B2 = c.x - d.x;
    long long C2 = A2 * c.x + B2 * c.y;

    long long det = A1 * B2 - A2 * B1;

    if (det == 0) return false;

    x = static_cast<double>(B2 * C1 - B1 * C2) / det;
    y = static_cast<double>(A1 * C2 - A2 * C1) / det;
    return true;
}

/*
* Check if segments ab and cd intersect
* Returns a vector of points
* Contains 0, 1 or 2 points depending on if no intersection, one intersection or segment intersection
* Complexity: O(1)
*/
template <typename T>
vector<Point2D<double>> segmentIntersection(Point2D<T> a, Point2D<T> b,
                                                 Point2D<T> c, Point2D<T> d) {
    vector<Point2D<double>> result;

    // Calculate orientations
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);

    // Intersection at one point
    if (o1 * o2 < 0 && o3 * o4 < 0) { // Segments are not colinear
        double x, y;
        if (lineIntersection(a, b, c, d, x, y)) { // Check if lines intersect
            result.emplace_back(x, y);
        }
        return result;
    }

    // Colinear case
    vector<Point2D<T>> points;
    if (o1 == 0 && onSegment(a, b, c)) points.push_back(c);
    if (o2 == 0 && onSegment(a, b, d)) points.push_back(d);
    if (o3 == 0 && onSegment(c, d, a)) points.push_back(a);
    if (o4 == 0 && onSegment(c, d, b)) points.push_back(b);

    // Sorting and removing duplicates
    sort(points.begin(), points.end(), [](const Point2D<T>& p1, const Point2D<T>& p2) {
        return (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y));
    });

    points.erase(unique(points.begin(), points.end()), points.end());

    for (const auto& pt : points) {
        result.emplace_back(static_cast<double>(pt.x), static_cast<double>(pt.y));
    }

    return result;
}

#endif 
