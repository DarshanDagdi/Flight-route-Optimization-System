#pragma once
#include "AirportGraph.h"

class RouteFinder {
private:
    const AirportGraph& graph;

public:
    RouteFinder(const AirportGraph& g);
    void findShortestRoute(string src, string dest);
};
