#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <algorithm>
#include <limits>
#include <queue>

using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;
using std::pair;

void addingEdgeToGraph(unordered_map<uint64_t, unordered_map<uint64_t, uint64_t>> &graph, uint64_t currentVertex, uint64_t vertexNeighbor, uint64_t weight)
{
    graph[currentVertex][vertexNeighbor] = weight;
    graph[vertexNeighbor][currentVertex] = weight;
}

const uint64_t INF = std::numeric_limits<uint64_t>::max();

void dijkstra(const unordered_map<uint64_t, unordered_map<uint64_t, uint64_t>> &graph, uint64_t start, unordered_map<uint64_t, uint64_t> &distance, unordered_map<uint64_t, uint64_t> &predecessor)
{
    for(const auto &current : graph)
    {
        distance[current.first] = INF;
        predecessor[current.first] = INF;
    }

    distance[start] = 0;

    std::priority_queue<std::pair<uint64_t, uint64_t>, vector<pair<uint64_t, uint64_t>>, std::greater<>> pq;
    pq.emplace(0, start);

    while(!pq.empty())
    {
        uint64_t currentDistance = pq.top().first;
        uint64_t currentVertex = pq.top().second;
        pq.pop();

        if(currentDistance > distance[currentVertex])
        {
            continue;
        }

        for(const auto &neighbor : graph.at(currentVertex))
        {
            uint64_t neighborVertex = neighbor.first;
            uint64_t neighborDistance = neighbor.second;

            if(currentDistance + neighborDistance < distance[neighborVertex])
            {
                distance[neighborVertex] = currentDistance + neighborDistance;
                predecessor[neighborVertex] = currentVertex; // Update predecessor
                pq.emplace(distance[neighborVertex], neighborVertex);
            }
        }
    }
}

void printingShortestPath(uint64_t start, uint64_t end, const unordered_map<uint64_t, uint64_t> &predecessor, const unordered_map<uint64_t, uint64_t> &distance)
{
    if(distance.at(end) == INF)
    {
        cout << "Нет пути от вершины " << start << " до вершины " << end << endl;
        return;
    }

    vector<uint64_t> path;
    for(uint64_t vertex = end; vertex != INF; vertex = predecessor.at(vertex))
    {
        path.push_back(vertex);
    }

    std::reverse(path.begin(), path.end());

    cout << "Кратчайший путь от вершины " << start << " до вершины " << end << " равен " << distance.at(end) << endl;
    cout << "Сам путь: ";
    for(size_t i = 0; i < path.size(); ++i)
    {
        cout << path[i];
        if(i < path.size() - 1)
        {
            cout << " -> ";
        }
    }

    cout << endl;
}

int main()
{
    unordered_map<uint64_t, unordered_map<uint64_t, uint64_t>> graph;
    addingEdgeToGraph(graph, 0, 1, 4);
    addingEdgeToGraph(graph, 0, 2, 1);
    addingEdgeToGraph(graph, 0, 3, 7);
    addingEdgeToGraph(graph, 1, 4, 3);
    addingEdgeToGraph(graph, 2, 5, 6);
    addingEdgeToGraph(graph, 2, 9, 2);

    const uint64_t start = 0;
    unordered_map<uint64_t, uint64_t> distance;
    unordered_map<uint64_t, uint64_t> predecessor;

    dijkstra(graph, start, distance, predecessor);

    const uint64_t end = 9;
    printingShortestPath(start, end, predecessor, distance);

    return EXIT_SUCCESS;
}