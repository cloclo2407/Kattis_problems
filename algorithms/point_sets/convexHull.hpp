// Chloé Leyssens

#ifndef CONVEX_HULL_HPP
#define CONVEX_HULL_HPP

#include <vector>
#include <algorithm>
#include "point2D.hpp"

using namespace std;

/*
* Computes the convex hull of a set of 2D points using Andrew's monotone chain algorithm.
* The algorithm sorts the points and constructs the lower and upper hulls.
* The result is a vector of indices representing the points in the convex hull in counterclockwise order.
* Complexity: O(n log n)
*/
template<typename T>
vector<int> convex_hull(const vector<Point2D<T>>& input_points) {
    int n = input_points.size();

    // Pair points with their original indices
    vector<pair<Point2D<T>, int>> points;
    for (int i = 0; i < n; ++i) {
        points.emplace_back(input_points[i], i);
    }

    // Sort
    sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
        return (a.first.x < b.first.x) || 
               (a.first.x == b.first.x && a.first.y < b.first.y);
    });

    // Remove duplicates
    points.erase(unique(points.begin(), points.end(), [](const auto& a, const auto& b) {
        return a.first == b.first;
    }), points.end());

    if (points.size() == 1) return {points[0].second};

    vector<pair<Point2D<T>, int>> hull(2 * points.size());
    int k = 0;

    // Lower hull
    for (size_t i = 0; i < points.size(); ++i) {
        while (k >= 2 && (hull[k-1].first - hull[k-2].first).cross(points[i].first - hull[k-2].first) <= 0)
            k--;
        hull[k++] = points[i];
    }

    // Upper hull
    for (int i = points.size() - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && (hull[k-1].first - hull[k-2].first).cross(points[i].first - hull[k-2].first) <= 0)
            k--;
        hull[k++] = points[i];
    }

    hull.resize(k);

    // Remove the last point because it's repeated at the beginning of the hull
    if (hull.size() > 1)
        hull.pop_back();

    // Extract and return the indices
    vector<int> result;
    for (const auto& p : hull)
        result.push_back(p.second);

    return result;
}

#endif
