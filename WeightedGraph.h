#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <vector>
#include "Vertex.h"
class WeightedGraph
{
    public:
        WeightedGraph(int);
        int indexIs(Vertex*);
        void DFS(Vertex*);
        void BFS(Vertex*);
        void clearMarks();
        void addVertex(Vertex*);
        void addEdge(int,int,int);
        void doDFS(Vertex*);
        void doBFS(Vertex*);
        void findPath(int, int);
        bool isPath(Vertex*, Vertex*, int&, int&);
    private:
        static const int NULL_EDGE = 0;
        int m_numVertices;
        int m_maxVertices;
        vector <Vertex*> m_vertices;
        vector <vector <int>> m_edges;
        vector <bool> m_marks;
        vector<Vertex*> m_path;
};
#endif // WEIGHTEDGRAPH_H
