#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <cstdint>
#include <algorithm>

void addingEdgeToGraph(std::unordered_map<uint64_t, std::list<uint64_t>> &graph, uint64_t currentVertex, uint64_t vertexNeighbor)
{
    if(graph.find(currentVertex) == graph.end())
    {
        graph[currentVertex] = std::list<uint64_t>();
    }

    if(graph.find(vertexNeighbor) == graph.end())
    {
        graph[vertexNeighbor] = std::list<uint64_t>();
    }

    if(std::find(graph[currentVertex].begin(), graph[currentVertex].end(), vertexNeighbor) == graph[currentVertex].end())
    {
        graph[currentVertex].push_back(vertexNeighbor);
    }
}

void DFS(std::unordered_map<uint64_t, std::list<uint64_t>> &graph, uint64_t start)
{
    std::unordered_map<uint64_t, bool> visited;
    std::stack<uint64_t> stack;

    for(const auto &pair : graph)
    {
        visited[pair.first] = false;
    }

    stack.push(start);

    while(!stack.empty())
    {
        uint64_t vertex = stack.top();
        stack.pop();

        if(!visited[vertex])
        {
            std::cout << vertex << " ";
            visited[vertex] = true;
        }

        if(graph.find(vertex) != graph.end())
        {
            for(const uint64_t &neighbor: graph[vertex])
            {
                if(!visited[neighbor])
                {
                    stack.push(neighbor);
                }
            }
        }
    }
}

int main()
{
    std::unordered_map<uint64_t, std::list<uint64_t>> graph;
    addingEdgeToGraph(graph, 0, 1);
    addingEdgeToGraph(graph, 0, 2);
    addingEdgeToGraph(graph, 0, 3);
    addingEdgeToGraph(graph, 1, 4);
    addingEdgeToGraph(graph, 2, 5);
    addingEdgeToGraph(graph, 2, 9);

    std::cout << "Vertices: ";
    DFS(graph, 0);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}