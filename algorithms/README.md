# Classical Algorithms

This folder contains reusable implementations of classic algorithms used in competitive programming.

- **Geometry:**
  - `point2D.hpp`: class template for 2D points with various operations
  - `polygon.hpp`: class template for 2D polygons
  - `segmentIntersection.hpp`: intersection of 2 segments
  - `segmentsDistance.hpp`: shortest distance between two segments
- **Graphs:**
  - `graph.cpp`: directed graph represented as an adjacency list
  - `edge.hpp`: edges for the different algorithms
  - `bellmanFord.cpp`: shortest path from a given source to all other nodes in a directed graph, handles negative weights
  - `dijkstra.cpp`: shortest paths from a given source to all other nodes with non-negative weights
  - `dijkstra_time_table.cpp`: dijkstra's algorithm for time-table shortest paths
  - `eulerianPath.cpp`: finds an Eulerian path in a graph using Depth-First Search (DFS) algorithm
  - `fastDijkstra.cpp`: dijkstra with potential/Johnson's algorithm
  - `FloydWarshall.cpp`: Floyd-Warshall algorithm for all pairs shortest path
  - `MinCostMaxFlow.cpp`: Computes the maximum flow and the minimum cost of a maximum flow from the source to the sink
- **Number_theory:**
  - `arithmetic.hpp`: classic arithmetic
  - `modularArithmetic.hpp`: operations and algorithms of modular arithmetic
  - `PrimeSieve.hpp`: prime numbers up to n
- **Point_sets:**
  - `point2D.hpp`: class template for 2D points
  - `closestPair.cpp`: find the closest pair of points in a set of points
  - `colinearPoints.hpp`: finds the maximum number of collinear points in a set of 2D points
  - `convexHull`: convex hull of a set of 2D points using Andrew's monotone chain algorithm
- **Strings:**
  - `ahoCorasick.cpp`: ahoCorasick algorithm to find patterns in a text
  - `kmp.cpp`: Knuth-Morris-Pratt algorithm to find a pattern in a text
  - `suffixArray.cpp`: computes suffixArray sorted in lexicographical order
