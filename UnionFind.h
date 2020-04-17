//
// Created by Joseph McFarland on 16-Apr-20.
//

#ifndef A6_CS368_UNIONFIND_H
#define A6_CS368_UNIONFIND_H

#include "SetUF.h"


class UnionFind<T> {
private:
    /*
     * A container to store all the set singletons.
     */
    vector<SetUF<T>> sets;

public:
    /*
     * A parametrized constructor to add the singletons to the container sets
     */
    UnionFind(const vector<T> &singletons) {
        for (auto v: *singletons) {
            sets.push_back(new SetUF(v))
        }
    }

    /*
     * find gives the root of the set to which the node belongs to.
     */
    SetUF<T>& find(T node) {
        for (auto set: sets) {
            if (set.value == node) {

                SetUF<T> root = set;
                while (root.parent != root) {
                    root = root.parent;
                }

                SetUF<T> parent;
                while (set.parent != root) {
                    parent = set.parent;
                    set.parent = root;
                    set = parent;
                }

                return root
            }
        }
    }

    /*
     * Creates a union by rank
     */
    void unionOp(SetUF<T> &x, SetUF<T> &y) {
        xRoot = find(x.value);
        yRoot = find(y.value);

        if (xRoot == yRoot) {
            return
        } else if (xRoot.rank < yRoot.rank) {
            xRoot.parent = yRoot;
        } else if (xRoot.rank > yRoot.rank) {
            yRoot.parent = xRoot;
        } else {
            xRoot.parent = yRoot;
            yRoot.rank += 1;
        }
    }

    /*
     * Creates a union by rank
     */
    void unionOp(T x, SetUF<T> &y) {
        xRoot = find(x);
        yRoot = find(y.value);

        if (xRoot == yRoot) {
            return
        } else if (xRoot.rank < yRoot.rank) {
            xRoot.parent = yRoot;
        } else if (xRoot.rank > yRoot.rank) {
            yRoot.parent = xRoot;
        } else {
            xRoot.parent = yRoot;
            yRoot.rank += 1;
        }
    }

    /*
     * Creates a union by rank
     */
    void unionOp(SetUF<T> &x, T y) {
        xRoot = find(x.value);
        yRoot = find(y);

        if (xRoot == yRoot) {
            return
        } else if (xRoot.rank < yRoot.rank) {
            xRoot.parent = yRoot;
        } else if (xRoot.rank > yRoot.rank) {
            yRoot.parent = xRoot;
        } else {
            xRoot.parent = yRoot;
            yRoot.rank += 1;
        }
    }

    /*
     * Creates a union by rank
     */
    void unionOp(T x, T y) {
        xRoot = find(x);
        yRoot = find(y);

        if (xRoot == yRoot) {
            return
        } else if (xRoot.rank < yRoot.rank) {
            xRoot.parent = yRoot;
        } else if (xRoot.rank > yRoot.rank) {
            yRoot.parent = xRoot;
        } else {
            xRoot.parent = yRoot;
            yRoot.rank += 1;
        }
    }

};

#endif //A6_CS368_UNIONFIND_H
