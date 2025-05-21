// Chloé Leyssens

#include <vector>
#include <map>
#include <algorithm>
#include <numeric>  
#include "point2D.hpp" 

using namespace std;

/*
* Finds the maximum number of collinear points in a set of 2D points.
* Calculate the slope between each pair of points.
* Returns an int representing the maximum number of collinear points.
* Complexity: O(n^2logn)
*/
template<typename T>
int number_of_colinear(const vector<Point2D<T>>& points) {
    int n = points.size();
    if (n < 2) return n;

    int maxColinear = 0;

    for (int i = 0; i < n; ++i) {
        map<pair<T, T>, int> slopeCount; // Map the slope to its count
        int duplicates = 1;  // Count the duplicates of the pivot point
        int localMax = 0;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue; // Skip the pivot point

            T dx = points[j].x - points[i].x;
            T dy = points[j].y - points[i].y;

            if (dx == 0 && dy == 0) {
                ++duplicates;  // Same as pivot
            } else {
                // Reduce slope to its simplest form
                T gcd = std::gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;

                // Normalize slope direction: make dx positive
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    // Vertical line: normalize dy
                    dy = 1;
                }

                slopeCount[{dy, dx}]++; // Increment the count for this slope
                localMax = max(localMax, slopeCount[{dy, dx}]);
            }
        }

        maxColinear = max(maxColinear, localMax + duplicates);
    }

    return maxColinear;
}
