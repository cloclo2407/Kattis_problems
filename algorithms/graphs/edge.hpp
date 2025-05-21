#ifndef EDGE_H
#define EDGE_H

/*
 * An edge in a graph represented as an integer u (source), integer v(destination), and long long weight.
 * Can also be represented as an integer u (source), integer v(destination), an intial time t0, a factor P, and a duration d for shortest path time table
 *
 * @param u: The first node of the edge
 * @param v: The second node of the edge
 * @param weight : The weight of the edge
 * @param t0 : The first time the edge is available in time table
 * @param P : The frequence at which the edge is available in time table
 * @param d: The duration to traverse the edge
*/
class Edge {
public:
    int u, v;
    long long weight;
    int t0, P, d;
    int cost;

    /*
     * Constructor for a classique Edge
    */
    Edge(int u, int v, long long weight) : u(u), v(v), weight(weight) { }

    /*
     * Constructor for a shortest path time table Edge
    */
    Edge(int u, int v, int t0, int P, int d) : u(u), v(v), t0(t0), P(P), d(d) { }

    Edge(int u, int v) : u(u), v(v) {}

};

#endif