//Chloé Leyssens

#ifndef CLOSEST_PAIR_HPP
#define CLOSEST_PAIR_HPP

#include <vector>
#include "point2D.hpp"

using Point = Point2D<double>; 
 
/*
* Function to calculate the squared distance between two points a and b
* Returns a double, which is the squared distance between the two points.
*/
double distance(const Point &a, const Point &b);

/*
* Calculates the closest pair of points using a brute-force approach
* Compares all pairs of points in the given range [left, right]
* Returns a pair of points that are closest to each other
* Complexity: O(n^2)
*/
std::pair<Point, Point> bruteForce(const std::vector<Point> &points, int left, int right);

/*
* Function to find the closest pair of points in a strip of width 2d
* The strip is sorted by y-coordinate
* Complexity: O(n) with n being the number of points in the strip
*/
std::pair<Point, Point> closestPairInStrip(const std::vector<Point> &strip, double d, std::pair<Point, Point> &minPair);

/*
* Recursive function to find the closest pair of points set in the given x range [left, right]
* PointsX has to be sorted by x-coordinate
* PointsY has to be sorted by y-coordinate
* Returns the closest pair of points in the range
*/
std::pair<Point, Point> closestPairUtil(std::vector<Point> &pointsX, std::vector<Point> &pointsY, int left, int right);

/*
* Main function to find the closest pair of points in a set of points
* Returns a pair of points that are closest to each other
* Complexity: O(n log n)
*/
std::pair<Point, Point> closestPair(std::vector<Point> &points);

#endif // CLOSEST_PAIR_HPP
