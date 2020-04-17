//
// Joseph McFarland
// 9072511679
// mcfarland3@wis.edu
// https://canvas.wisc.edu/courses/188843/files for slides
// Made in CLion with commits to GitHub
//

#ifndef A6_CS368_SETUF_H
#define A6_CS368_SETUF_H

#include <vector>
#include <utility>
#include <iostream>
#include "UnionFind.h"

template <typename T>
class UnionFind;

using namespace std;

template<typename T>
class SetUF {
private:
    /*
     * The value of one item of a set.
     */
    T value;

    /*
     * Rank roughly gives a measure of the depth of the tree for a set.
     */
    unsigned rank;

    /*
     * A member variable to store the parent node of this node of the set.
     */
    SetUF *parent;

public:
    /*
     * A Parametrized constructor to set the value of the node.
     */
    SetUF(T v) {
        value = v;
        rank = 0;
        parent = this;
    }

    /*
     * A copy constructor
     */
    SetUF(const SetUF &a) {
        value = a.value;
        rank = 0;
        parent = this;
    }

    /*
     * An assignment operator
     */
    SetUF& operator=(const SetUF &a) {
        if (this != &a) {
            value = a.value;
            rank = 0;
            parent = this;
        }
        return *this;
    }

    /*
     * A conversion function to implicitly cast SetUF object to type T.
     */
    operator T () const { return value; }

    /*
     * UnionFind<T> class should be a friend of SetUF<T> as union and find
     * operations need access to private members of SetUF<T>, e.g. rank and
     * parent.
     */
    friend class UnionFind<T>;
};


#endif //A6_CS368_SETUF_H
