#include <iostream>
#include <cstdint>
#include <ranges>
#include <queue>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

void addingEdgeToGraph(vector<vector<uint64_t>> &graph, uint64_t currentVertex, uint64_t vertexNeighbor)
{
    if(graph.size() <= std::max(currentVertex, vertexNeighbor))
    {
        graph.resize(std::max(currentVertex, vertexNeighbor) + 1);
    }

    graph[currentVertex].push_back(vertexNeighbor);
    graph[vertexNeighbor].push_back(currentVertex);
}

void BFS(vector<vector<uint64_t>> &graph, uint64_t startVertex)
{
    const uint64_t lenGraph = graph.size();
    vector<bool> visited(lenGraph, false);

    queue<uint64_t> queue;
    queue.push(startVertex);

    while(!queue.empty())
    {
        uint64_t vertex = queue.front();
        queue.pop();

        if(!visited[vertex])
        {
            cout << vertex << " ";
            visited[vertex] = true;
        }

        for(uint64_t iter : std::ranges::reverse_view(graph[vertex]))
        {
            if(!visited[iter])
            {
                queue.push(iter);
            }
        }
    }
}

int main()
{
    vector<vector<uint64_t>> graph;
    addingEdgeToGraph(graph, 0, 1);
    addingEdgeToGraph(graph, 0, 2);
    addingEdgeToGraph(graph, 0, 3);
    addingEdgeToGraph(graph, 1, 4);
    addingEdgeToGraph(graph, 2, 5);
    addingEdgeToGraph(graph, 2, 9);

    BFS(graph, 0);
    cout << endl;

    return EXIT_SUCCESS;
}
