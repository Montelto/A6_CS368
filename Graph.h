//
// Created by Joseph McFarland on 16-Apr-20.
//

#ifndef A6_CS368_GRAPH_H
#define A6_CS368_GRAPH_H

#include "UnionFind.h"

template<typename T> using Edge = pair<T, T>;

template<typename T>
class Graph {
    /*
     * provides a name for data pair
     */
    using Edge = pair<T, T>;

private:
    /*
     * the vertices  containing the data type
     */
    vector<T> vertices;

    /*
     * the path or connecting between vertices
     */
    vector<Edge> edges;

public:
    /*
     * parameterized constructor
     */
    Graph(vector<T> v, vector<Edge> e) :
        vertices(v), edges(e) {
    }

    /*
     * adds path between two vertices
     */
    void addEdge(Edge e) {
        edges.push_back(e);

    };

    /*
     * for finding if graph contains a cycle
     */
    bool containsCycle();

};

template<typename T>
bool Graph<T>::containsCycle() {
    UnionFind<T> uFind(vertices);

    for (Edge &e : edges) {
        SetUF<T> &xRoot = uFind.find(e.first);

        SetUF<T> &yRoot = uFind.find(e.second);

        if (xRoot == yRoot)
            return true;

        uFind.unionOp(xRoot, yRoot);

    }

    return false;

}
#endif
