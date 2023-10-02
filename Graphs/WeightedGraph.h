#pragma once

#include "Graph.h"

class WeightedGraph : public Graph {
public:
    WeightedGraph(int numVertices);
    WeightedGraph(int numVertices, double p, int minWeight, int maxWeight);
    void addEdge(int from, int to, int weight) override;
    void removeEdge(int from, int to) override;
    void printGraph() override;
    std::vector<std::vector<int>> toAdjacencyMatrix() const override;

private:
    std::vector<std::vector<int>> weightMatrix;
};
