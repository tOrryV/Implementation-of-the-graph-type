// WeightedGraph.cpp
#include "WeightedGraph.h"
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

WeightedGraph::WeightedGraph(int numVertices) : Graph(numVertices) {
    // Ініціалізуємо weightMatrix з правильними розмірами
    weightMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
}

WeightedGraph::WeightedGraph(int numVertices, double p, int minWeight, int maxWeight) : Graph(numVertices) {
    std::default_random_engine generator(static_cast<unsigned>(time(nullptr)));
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::uniform_int_distribution<int> weightDistribution(minWeight, maxWeight);

    // Ініціалізуємо weightMatrix з правильними розмірами
    weightMatrix.resize(numVertices, std::vector<int>(numVertices, 0));

    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            if (distribution(generator) <= p) {
                int weight = weightDistribution(generator);
                addEdge(i, j, weight);
            }
        }
    }
}

void WeightedGraph::addEdge(int from, int to, int weight) {
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);

        weightMatrix[from][to] = weight;
        weightMatrix[to][from] = weight;
    }
}

void WeightedGraph::removeEdge(int from, int to) {
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
        adjacencyList[from].erase(std::remove(adjacencyList[from].begin(), adjacencyList[from].end(), to), adjacencyList[from].end());
        adjacencyList[to].erase(std::remove(adjacencyList[to].begin(), adjacencyList[to].end(), from), adjacencyList[to].end());

        weightMatrix[from][to] = 0;
        weightMatrix[to][from] = 0;
    }
}

void WeightedGraph::printGraph() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "The vertex " << i << " is connected to the vertices: ";
        for (int neighbor : adjacencyList[i]) {
            std::cout << neighbor << " (weight: " << weightMatrix[i][neighbor] << ") ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> WeightedGraph::toAdjacencyMatrix() const {
    std::vector<std::vector<int>> matrix(numVertices, std::vector<int>(numVertices, 0));

    for (int i = 0; i < numVertices; ++i) {
        for (int neighbor : adjacencyList[i]) {
            matrix[i][neighbor] = weightMatrix[i][neighbor];
        }
    }

    return matrix;
}
