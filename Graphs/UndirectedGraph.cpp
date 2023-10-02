#include "UndirectedGraph.h"
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

UndirectedGraph::UndirectedGraph(int numVertices) : Graph(numVertices) {}

UndirectedGraph::UndirectedGraph(int numVertices, double p) : Graph(numVertices) {
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

void UndirectedGraph::addEdge(int from, int to, int weight) {
    // ƒодати ребро в список сум≥жност≥
    adjacencyList[from].push_back(to);
    adjacencyList[to].push_back(from); // ƒл€ неор≥Їнтованого графа
}

void UndirectedGraph::removeEdge(int from, int to) {
    adjacencyList[from].erase(std::remove(adjacencyList[from].begin(), adjacencyList[from].end(), to), adjacencyList[from].end());
    adjacencyList[to].erase(std::remove(adjacencyList[to].begin(), adjacencyList[to].end(), from), adjacencyList[to].end());
}

void UndirectedGraph::printGraph() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "The vertex " << i << " is connected to the vertices: ";
        for (int neighbor : adjacencyList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> UndirectedGraph::toAdjacencyMatrix() const {
    std::vector<std::vector<int>> matrix(numVertices, std::vector<int>(numVertices, 0));

    for (int i = 0; i < numVertices; ++i) {
        for (int neighbor : adjacencyList[i]) {
            matrix[i][neighbor] = 1; // якщо ребро ≥снуЇ, встановлюЇмо 1
        }
    }

    return matrix;
}
