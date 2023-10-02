#pragma once
#include <vector>

class Graph {
public:
    Graph(int numVertices);
    virtual void addEdge(int from, int to, int weight = 1) = 0;
    virtual void removeEdge(int from, int to) = 0;
    virtual void addVertex();
    virtual void printGraph() = 0;
    virtual std::vector<std::vector<int>> toAdjacencyMatrix() const;
    virtual std::vector<std::vector<int>> toAdjacencyList() const;
    bool isConnected() const;
    bool isStronglyConnected() const;

private:
    void dfs(int vertex, std::vector<bool>& visited) const;

protected:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
};
