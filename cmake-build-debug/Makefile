# A6_368
# Joseph McFarland
# 9072511679
# mcfarland3@wisc.edu

CXX = g++
CXXFLAGS = -Wall -g

demo.o: demo.cpp SetUF.h UnionFind.h Graph.h
	$(CXX) $(CXXFLAGS) -c demo.cpp

clean:
	-rm demo.o
	-rm UnionFind

SummarizeGrades: demo.o
	$(CXX) $(CXXFLAGS) -o UnionFind demo.o
