#include "Graph.h"
#include <iostream>

Graph::Graph(int numVertices) : numVertices(numVertices) {
    adjacencyList.resize(numVertices);
}

void Graph::addVertex() {
    // �������� ������� ������ � ����� �� ����
    ++numVertices;

    // ������ ����� ����� (��� ��������) �� ������ �������� (��� ������� ���)
    adjacencyList.resize(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        adjacencyList[i].resize(numVertices);
    }
}

std::vector<std::vector<int>> Graph::toAdjacencyMatrix() const {
    return adjacencyList;
}

std::vector<std::vector<int>> Graph::toAdjacencyList() const {
    return adjacencyList;
}

bool Graph::isConnected() const {
    // ��������� ������ �������� ������ �� ���������� ���� ���������� false
    std::vector<bool> visited(numVertices, false);

    // ������� ����� ������� � �������� � �� DFS
    dfs(0, visited);

    // ����������, �� �� ������� ���� ������
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    return true;
}

bool Graph::isStronglyConnected() const {
    // ��������� ������� ��������
    std::vector<std::vector<int>> adjacencyMatrix = toAdjacencyMatrix();

    // ��������� ������� ������
    int n = numVertices;

    // ������� ������� ��������� � ����������� �� ���������� ������� ��������
    std::vector<std::vector<bool>> reachabilityMatrix(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                reachabilityMatrix[i][j] = true;
            }
        }
    }

    // ��������� �������� ������� ��� �������� ������� ���������
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                reachabilityMatrix[i][j] = reachabilityMatrix[i][j] || (reachabilityMatrix[i][k] && reachabilityMatrix[k][j]);
            }
        }
    }

    // ��������, �� �� ������� ������ ������
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!reachabilityMatrix[i][j] && !reachabilityMatrix[j][i]) {
                return false;
            }
        }
    }

    return true;
}

void Graph::dfs(int vertex, std::vector<bool>& visited) const {
    visited[vertex] = true;

    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}
