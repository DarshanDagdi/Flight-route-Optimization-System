#include "RouteFinder.h"
#include <queue>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <iostream>

RouteFinder::RouteFinder(const AirportGraph& g) : graph(g) {}

void RouteFinder::findShortestRoute(string src, string dest) {
    auto adjList = graph.getGraph();
    unordered_map<string, int> dist;
    unordered_map<string, string> parent;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    // Replace structured binding with normal loop
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        string airport = it->first;
        dist[airport] = INT_MAX;
    }

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        pair<int, string> top = pq.top();
        pq.pop();
        int curDist = top.first;
        string node = top.second;

        for (const auto& edge : adjList[node]) {
            int newDist = curDist + edge.distance;
            if (newDist < dist[edge.destination]) {
                dist[edge.destination] = newDist;
                parent[edge.destination] = node;
                pq.push(make_pair(newDist, edge.destination));
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        cout << "No path found.\n";
        return;
    }

    vector<string> path;
    for (string at = dest; at != ""; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    cout << "Optimal Route: ";
    for (const auto& city : path)
        cout << city << " ";
    cout << "\nTotal Distance: " << dist[dest] << " km\n";
}
