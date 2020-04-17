//
// Created by Joseph McFarland on 16-Apr-20.
//

#include "Graph.h"

class Student {
    /*
     * for printing out data type
     */
    friend ostream& operator<<(ostream &strm, const Student &stud) {
        return strm << "student(" << stud.id << ", " << stud.name << ")";
    }
    /*
     * for data type comparison
     */
    friend bool operator==(const Student &lhs, const Student &rhs) {
        return lhs.id == rhs.id;
    }
    /*
     * for discomparison of data type
     */
    friend bool operator!=(const Student &lhs, const Student &rhs) {
        return !(lhs == rhs);
    }

public:
    /*
     * default and parameterized constructors
     */
    Student() = default;
    Student(int id, string name) :
        id(id), name(name) {
    }

private:
    /*
     * int fo student id
     */
    int id;
    /*
     * string for student name
     */
    string name;
};


/*
 * creates a graph with set names and id's to run tests on
 */
int main() {
    Student marc(0, "Marc");
    Student kyle(1, "Kyle");
    Student hemant(2, "Hemant");
    Student shanmathi(3, "Shanmathi");
    Student kate(4, "Kate");

    vector<Student> vertices { marc, kyle, hemant, shanmathi, kate };
    vector<Edge<Student>> edges { { marc, kyle }, { marc, hemant }, { kyle,shanmathi }, { kyle, kate } };
    Graph<Student> graph(vertices, edges);
    //No cycle
    if(graph.containsCycle())
        cout << "The graph contains a cycle" << endl;
    else
        cout << "The graph does not contain a cycle" << endl;

    cout << "Adding an edge to the current graph" << endl;
    graph.addEdge( { hemant, shanmathi });

    //cycle
    if(graph.containsCycle())
        cout << "The graph contains a cycle" << endl;
    else
        cout << "The graph does not contain a cycle" << endl;
    /*
     * * Add your graph examples below
     * */
}
