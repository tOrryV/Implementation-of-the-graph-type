#pragma once

#include "Graph.h"

class DirectedGraph : public Graph {
public:
    DirectedGraph(int numVertices);
    DirectedGraph(int numVertices, double p);
    void addEdge(int from, int to, int weight = 1) override;
    void removeEdge(int from, int to) override;
    void printGraph() override;
    std::vector<std::vector<int>> toAdjacencyMatrix() const override;
};
