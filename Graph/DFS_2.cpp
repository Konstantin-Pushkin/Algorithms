#include <iostream>
#include <cstdint>
#include <ranges>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
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

void DFS(vector<vector<uint64_t>> &graph, uint64_t startVertex)
{
    const uint64_t lenGraph = graph.size();
    vector<bool> visited(lenGraph, false);

    stack<uint64_t> stack;
    stack.push(startVertex);

    while(!stack.empty())
    {
        uint64_t vertex = stack.top();
        stack.pop();

        if(!visited[vertex])
        {
            cout << vertex << " ";
            visited[vertex] = true;
        }

        for(unsigned long & iter : std::ranges::reverse_view(graph[vertex]))
        {
            if(!visited[iter])
            {
                stack.push(iter);
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


    DFS(graph, 0);
    cout << endl;

    return EXIT_SUCCESS;
}