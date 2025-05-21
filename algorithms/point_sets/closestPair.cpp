//Chloé Leyssens

#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cfloat>
#include "closestPair.hpp"
#include "point2D.hpp"

using namespace std;

/*
* Comparison function to sort points based on x-coordinate.
*/
bool compareX(const Point &a, const Point &b) {
    return a.x < b.x;
}

/*
* Comparison function to sort points based on y-coordinate.
*/
bool compareY(const Point &a, const Point &b) {
    return a.y < b.y;
}

double distance(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

pair<Point, Point> bruteForce(const vector<Point> &points, int left, int right) {
    double minDist = numeric_limits<double>::max();
    pair<Point, Point> closestPair;

    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
                closestPair = {points[i], points[j]};
            }
        }
    }

    return closestPair;
}

pair<Point, Point> closestPairInStrip(const vector<Point> &strip, double d, pair<Point, Point> &minPair) {
    double minDist = d;
    int n = strip.size();

    // Check all pairs of points in the strip
    for (int i = 0; i < n; ++i) {
        // Stops checking if the y-coordinate difference is greater than minDist (check max 7 points)
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < minDist; ++j) {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
                minPair = {strip[i], strip[j]};
            }
        }
    }

    return minPair;
}

pair<Point, Point> closestPairUtil(vector<Point> &pointsX, vector<Point> &pointsY, int left, int right) {
    if (right - left + 1 <= 3) {
        return bruteForce(pointsX, left, right);
    }

    int mid = left + (right - left) / 2;
    Point midPoint = pointsX[mid];

    // Create two vectors to hold points in the left and right halves
    vector<Point> leftY, rightY;
    for (const Point &p : pointsY) {
        if (p.x <= midPoint.x) {
            leftY.push_back(p);
        } else {
            rightY.push_back(p);
        }
    }

    // Recursively find the closest pair in the left and right halves
    pair<Point, Point> leftClosest = closestPairUtil(pointsX, leftY, left, mid);
    pair<Point, Point> rightClosest = closestPairUtil(pointsX, rightY, mid + 1, right);

    // Keep minimum distance found so far
    double leftDist = distance(leftClosest.first, leftClosest.second);
    double rightDist = distance(rightClosest.first, rightClosest.second);
    double minDist = min(leftDist, rightDist);
    pair<Point, Point> minPair = (leftDist < rightDist) ? leftClosest : rightClosest; // closest pair so far

    // Points within minDist of mid line
    vector<Point> strip;
    for (const Point &p : pointsY) {
        if ((p.x - midPoint.x) * (p.x - midPoint.x) < minDist) {
            strip.push_back(p);
        }
    }

    // Find closest in strip
    pair<Point, Point> stripClosest = closestPairInStrip(strip, minDist, minPair);
    double stripDist = distance(stripClosest.first, stripClosest.second);

    // Compare the closest pair found in the strip with the closest pair found so far
    if (stripDist < minDist) {
        return stripClosest;
    } else {
        return minPair;
    }
}

pair<Point, Point> closestPair(vector<Point> &points) {
    vector<Point> pointsX = points;
    vector<Point> pointsY = points;

    sort(pointsX.begin(), pointsX.end(), compareX);
    sort(pointsY.begin(), pointsY.end(), compareY);

    // Check for duplicate points
    for (int i = 1; i < pointsX.size(); ++i) {
        if (pointsX[i] == pointsX[i - 1]) {
            return {pointsX[i - 1], pointsX[i]};
        }
    }

    return closestPairUtil(pointsX, pointsY, 0, points.size() - 1);
}
