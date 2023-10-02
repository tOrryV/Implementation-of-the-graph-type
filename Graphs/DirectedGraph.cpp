#include "DirectedGraph.h"
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

DirectedGraph::DirectedGraph(int numVertices) : Graph(numVertices) {}

DirectedGraph::DirectedGraph(int numVertices, double p) : Graph(numVertices) {
    // ≤н≥ц≥ал≥зуЇмо генератор випадкових чисел
    std::default_random_engine generator(static_cast<unsigned>(time(nullptr)));
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    // √енеруЇмо ребра з ймов≥рн≥стю p
    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            if (distribution(generator) <= p) {
                addEdge(i, j);
            }
        }
    }
}

void DirectedGraph::addEdge(int from, int to, int weight) {
    // ƒодати ребро в список сум≥жност≥
    adjacencyList[from].push_back(to);
}

void DirectedGraph::removeEdge(int from, int to) {
    adjacencyList[from].erase(std::remove(adjacencyList[from].begin(), adjacencyList[from].end(), to), adjacencyList[from].end());
}

void DirectedGraph::printGraph() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "The vertex " << i << " output edges to vertices: ";
        for (int neighbor : adjacencyList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> DirectedGraph::toAdjacencyMatrix() const {
    std::vector<std::vector<int>> matrix(numVertices, std::vector<int>(numVertices, 0));

    for (int i = 0; i < numVertices; ++i) {
        for (int neighbor : adjacencyList[i]) {
            matrix[i][neighbor] = 1; // якщо ребро ≥снуЇ, встановлюЇмо 1
        }
    }

    return matrix;
}
