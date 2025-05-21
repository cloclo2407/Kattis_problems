#include "point2D.hpp"
#include <algorithm>  

using Point = Point2D<double>;

/// Shortest distance from a point to a segment.
double pointSegDist(const Point& p, const Point& a, const Point& b) {
    Point ab = b - a;
    Point ap = p - a;

    double ab_len = ab.magnitude();
    if (ab_len == 0.0) return p.distanceTo(a); // Degenerate segment

    Point ab_normalized = ab / ab_len;

    double t = ab_normalized.dot(ap);
    if (t < 0.0) {
        return p.distanceTo(a);
    } else if (t > ab_len) {
        return p.distanceTo(b);
    } else {
        Point projected_p = a + ab_normalized * t;
        return p.distanceTo(projected_p);
    }
}

/// Checks whether the two segments ab and cd intersect.
bool segmentsIntersect(const Point& a, const Point& b, const Point& c, const Point& d) {
    auto computeOrientation = [](const Point& a, const Point& b, const Point& c) -> double {
        Point ab = b - a;
        Point ac = c - a;
        return ab.cross(ac);
    };

    double o1 = computeOrientation(a, b, c);
    double o2 = computeOrientation(a, b, d);
    double o3 = computeOrientation(c, d, a);
    double o4 = computeOrientation(c, d, b);

    if ((o1 > 0) != (o2 > 0) && (o3 > 0) != (o4 > 0)) {
        return true;
    }

    return false;
}

/// Shortest distance between two segments.
double segmentDist(const Point& a, const Point& b, const Point& c, const Point& d) {
    if (segmentsIntersect(a, b, c, d)) {
        return 0.0;
    }

    double d1 = pointSegDist(a, c, d);
    double d2 = pointSegDist(b, c, d);
    double d3 = pointSegDist(c, a, b);
    double d4 = pointSegDist(d, a, b);

    return std::min({d1, d2, d3, d4});
}
