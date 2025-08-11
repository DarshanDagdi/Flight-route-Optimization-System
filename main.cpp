#include <iostream>
#include "AirportGraph.h"
#include "RouteFinder.h"

using namespace std;

int main() {
    AirportGraph graph;
    RouteFinder routeFinder(graph);
    int choice;
    string src, dest;
    int distance;

    while (true) {
        cout << "\n==== Flight Route Optimization System ====\n";
        cout << "1. Add Route\n2. Display Routes\n3. Find Shortest Route\n4. Save Data\n5. Load Data\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter source airport code: ";
            cin >> src;
            cout << "Enter destination airport code: ";
            cin >> dest;
            cout << "Enter distance in km: ";
            cin >> distance;
            graph.addRoute(src, dest, distance);
        } else if (choice == 2) {
            graph.displayRoutes();
        } else if (choice == 3) {
            cout << "Enter source: ";
            cin >> src;
            cout << "Enter destination: ";
            cin >> dest;
            routeFinder.findShortestRoute(src, dest);
        } else if (choice == 4) {
            graph.saveToFile("data.txt");
            
        } else if (choice == 5) {
            graph.loadFromFile("data.txt");
        } else if (choice == 6) {
            cout << "Saving routes before exit...\n";
            graph.saveToFile("data.txt"); // ✅ auto save!
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
