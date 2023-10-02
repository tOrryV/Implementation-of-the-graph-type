#pragma once

#include "Graph.h"

class UndirectedGraph : public Graph {
public:
    UndirectedGraph(int numVertices);
    UndirectedGraph(int numVertices, double p);
    void addEdge(int from, int to, int weight = 1) override;
    void removeEdge(int from, int to) override;
    void printGraph() override;
    std::vector<std::vector<int>> toAdjacencyMatrix() const override;
};
