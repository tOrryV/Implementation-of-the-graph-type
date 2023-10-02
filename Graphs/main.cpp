// main.cpp
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "WeightedGraph.h"
#include <iostream>

int main() {
    int numVertices = 5;
    double probability = 0.3; // Ймовірність з'єднання вершини ребром
    int minWeight = 1; // Мінімальна вага ребра
    int maxWeight = 10; // Максимальна вага ребра

    UndirectedGraph randomUndirectedGraph(numVertices, probability);

    std::cout << "Generated graph:" << std::endl;
    randomUndirectedGraph.printGraph();


    // Перевірка зв'язності зв допомогою рекурсивного DFS
    if (randomUndirectedGraph.isConnected()) {
        std::cout << "The graph is connected." << std::endl;
    }
    else {
        std::cout << "The graph is not connected." << std::endl;
    }


    // Перевірка зв'язності зв допомогою алгоритму Уоршелла
    if (randomUndirectedGraph.isStronglyConnected()) {
        std::cout << "The graph is connected." << std::endl;
    }
    else {
        std::cout << "The graph is not connected." << std::endl;
    }


    return 0;
}
