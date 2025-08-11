#pragma once
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Edge {
    string destination;
    int distance;
};

class AirportGraph {
private:
    unordered_map<string, vector<Edge>> adjList;

public:
    void addRoute(string src, string dest, int distance);
    void displayRoutes();
    const unordered_map<string, vector<Edge>>& getGraph() const;
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};
