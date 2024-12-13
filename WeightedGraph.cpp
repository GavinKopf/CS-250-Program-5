#include "weightedgraph.h"
#include <iostream>
#include <queue>
WeightedGraph::WeightedGraph(int size)
{
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size);
for (int i=0; i<size; i++){
        m_vertices[i] = NULL;
    }
    m_marks.resize(size);
    int rows = size;
    int columns = size;
    m_edges.resize(rows, vector<int>(columns, 0));
}
void WeightedGraph::addVertex(Vertex* aVertex)
{
    m_vertices[m_numVertices] = aVertex;
    for (int i=0; i<m_maxVertices; i++) {
        m_edges[m_numVertices][i] = NULL_EDGE;
        m_edges[i][m_numVertices] = NULL_EDGE;
    }
    m_numVertices++;
}
void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight)
{
    m_edges[fromVertex][toVertex] = weight;
}
int WeightedGraph::indexIs(Vertex* aVertex)
{
    int i = 0;
    while (i < m_numVertices) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
    i++;
    }
    return -1;
}
void WeightedGraph::clearMarks()
{
    for (int i=0; i<m_numVertices; i++) {
        m_marks[i] = false;
    }
}
void WeightedGraph::doDFS (Vertex* aVertex)
{
    int ix, ix2;
    if (aVertex == NULL) return;
        cout << aVertex->getTitle() << " ";
        ix = indexIs(aVertex);
        m_marks[ix] = true;
    for (int i=0; i<m_numVertices; i++) {
        ix2 = indexIs(m_vertices[i]);
        if(m_edges[ix][ix2] != NULL_EDGE) {
            if (m_marks[i] == false)
                doDFS(m_vertices[i]);
        }
    }
}
void WeightedGraph::DFS(Vertex* aVertex)
{
    clearMarks();
    doDFS(aVertex);


}
void WeightedGraph::doBFS(Vertex* aVertex)
{
    int ix,ix2;
    queue <Vertex*> que;
    ix = indexIs(aVertex);
    m_marks[ix] = true;
    que.push(aVertex);
    while (!que.empty()) {
        Vertex* node = que.front();
        que.pop();
        ix = indexIs(node);
        cout << node->getTitle() << " ";
        for (int i=0; i<m_numVertices; i ++) {
            ix2 = indexIs(m_vertices[i]);
            if (m_edges[ix][ix2] != NULL_EDGE) {
                if (m_marks[ix2] == false) {
                    m_marks[i] = true;
                    que.push(m_vertices[i]);
                    }
            }
        }
    }
}
void WeightedGraph::BFS(Vertex* aVertex)
{
    clearMarks();
    doBFS(aVertex);
}

void WeightedGraph::findPath(int s, int d)
{
    m_path.clear();
    int i;
    int n = 0;
    int weight = 0;
    if(s < 0 || s > m_numVertices -1 || d < 0 || d > m_numVertices -1 || s == d){
        cout << "Invalid source / destination values" << endl;
        return;
    }

    Vertex* source = m_vertices.at(s);
    Vertex* destination = m_vertices.at(d);
    bool b = isPath(source, destination, weight, n);
    if(!b){
        cout << "No path was found"<< endl;
    }
    else if(m_path.size() > 1){
        m_path.push_back(source);
        cout << "The path is: ";
        for(i = m_path.size() - 1; i > -1 ; i--){
            cout  << m_path.at(i)->getTitle() << " ";
        }
        cout << "\nWeigth: " << weight << endl;
    }
    else
        cout << "Value of path is invalid" << endl;
    m_path.clear();

}
bool WeightedGraph::isPath(Vertex* source, Vertex* destination, int & weight, int& n)
{
    int i, j;
    bool b;

    for (i = 0; i < m_numVertices; i++) {
        if(m_edges[indexIs(source)][i] != NULL_EDGE){
            if(m_vertices.at(i) == destination){
                m_path.push_back(destination);
                weight += m_edges[indexIs(source)][indexIs(destination)];
                return true;
            }
            else{
                n++;
                if (n < m_numVertices * 1.2 && isPath(m_vertices.at(i), destination, weight, n)){
                    m_path.push_back(m_vertices.at(i));
                    weight += m_edges[indexIs(source)][i];
                    return true;
                }
                else
                    return false;
            }
        }
    }
}

