// main.cpp
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "WeightedGraph.h"
#include <iostream>

int main() {
    int numVertices = 5;
    double probability = 0.3; // ��������� �'������� ������� ������
    int minWeight = 1; // ̳������� ���� �����
    int maxWeight = 10; // ����������� ���� �����

    UndirectedGraph randomUndirectedGraph(numVertices, probability);

    std::cout << "Generated graph:" << std::endl;
    randomUndirectedGraph.printGraph();


    // �������� ��'������ �� ��������� ������������ DFS
    if (randomUndirectedGraph.isConnected()) {
        std::cout << "The graph is connected." << std::endl;
    }
    else {
        std::cout << "The graph is not connected." << std::endl;
    }


    // �������� ��'������ �� ��������� ��������� ��������
    if (randomUndirectedGraph.isStronglyConnected()) {
        std::cout << "The graph is connected." << std::endl;
    }
    else {
        std::cout << "The graph is not connected." << std::endl;
    }


    return 0;
}
