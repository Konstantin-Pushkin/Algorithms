#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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

void BFS(std::unordered_map<uint64_t, std::list<uint64_t>> &graph, uint64_t start)
{
    std::unordered_map<uint64_t, bool> visited;
    std::queue<uint64_t> queue;

    for(const auto &pair : graph)
    {
        visited[pair.first] = false;
    }

    visited[start] = true;
    queue.push(start);

    while(!queue.empty())
    {
        uint64_t vertex = queue.front();
        std::cout << vertex << " ";
        queue.pop();

        if(graph.find(vertex) != graph.end())
        {
            for(const uint64_t &neighbor: graph.at(vertex))
            {
                if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue.push(neighbor);
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
    BFS(graph, 0);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}