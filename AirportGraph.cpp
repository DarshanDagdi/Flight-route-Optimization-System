#include "AirportGraph.h"
#include <iostream>
#include <fstream>

void AirportGraph::addRoute(string src, string dest, int distance) {
    adjList[src].push_back({dest, distance});
    adjList[dest].push_back({src, distance});
}

void AirportGraph::displayRoutes() {
    cout << "\nCurrent Routes:\n";
    for (auto& pair : adjList) {
        string src = pair.first;
        vector<Edge>& edges = pair.second;
        for (auto& edge : edges) {
            cout << src << " -> " << edge.destination << " = " << edge.distance << " km\n";
        }
    }
}


const unordered_map<string, vector<Edge>>& AirportGraph::getGraph() const {
    return adjList;
}

void AirportGraph::saveToFile(const string& filename) {
    ofstream fout(filename);
        for (auto& pair : adjList) {
        string src = pair.first;
        vector<Edge>& edges = pair.second;
            for (auto& edge : edges) {
                cout << src << " -> " << edge.destination << " = " << edge.distance << " km\n";
            
            for (auto& edge : edges) {
                fout << src << " " << edge.destination << " " << edge.distance << "\n";
            }
            }
            fout.close();
            cout << "Routes saved to " << filename << "\n";
    }
}

void AirportGraph::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "File not found!\n";
        return;
    }
    adjList.clear();
    string src, dest;
    int distance;
    while (fin >> src >> dest >> distance) {
        addRoute(src, dest, distance);
    }
    fin.close();
    cout << "Routes loaded from " << filename << "\n";
}
