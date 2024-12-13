/*
Program that implements a weighted directed graph
Author: Dr. Vermilyer
Date: November 14, 2024
*/
#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"
using namespace std;
int main()
{
    WeightedGraph myGraph(10);
    Vertex* startNode;
    Vertex* aVertex;
    startNode = new Vertex("A"); // node 0
    myGraph.addVertex(startNode);
    aVertex = new Vertex("B"); // node 1
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("C"); // node 2
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("D"); // node 3
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("E"); // node 4
    myGraph.addVertex(aVertex);
    myGraph.addEdge(4,0,7);
    myGraph.addEdge(0,3,60);
    myGraph.addEdge(0,2,12);
    myGraph.addEdge(1,0,10);
    myGraph.addEdge(2,1,20);
    myGraph.addEdge(2,3,32);
    cout << "DFS: ";
    myGraph.DFS(startNode);
    cout << endl;
    cout << "BFS: ";
    myGraph.BFS(startNode);
    cout << "\n\n\nLooking for a path from C to A" << endl;
    myGraph.findPath(2, 0);
    cout << "\nLooking for a path from E to B" << endl;
    myGraph.findPath(4, 1);
    cout << "\nLooking for a path from D to B" << endl;
    myGraph.findPath(3, 1);
    cout << "\nLooking for an invaild path" << endl;
    myGraph.findPath(-55, 99);
return 0;
}
