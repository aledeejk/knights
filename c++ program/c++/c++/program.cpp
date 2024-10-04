#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Structure to represent the city
struct City {
    int x;
    int y;
};

// Function for calculating the distance between two cities
double distance(City city1, City city2) {
    return sqrt(pow(city1.x - city2.x, 2) + pow(city1.y - city2.y, 2));
}

// Function for solving the traveling salesman problem by the nearest neighbor method
vector<int> nearestNeighbor(vector<City>& cities) {
    int n = cities.size();
    vector<int> path(n); // Array for storing the route
    vector<bool> visited(n, false); // Array for tracking visited cities

    // Select the starting city
    int start = 0;
    path[0] = start;
    visited[start] = true;

    // Route Search
    for (int i = 1; i < n; i++) {
        // Looking for the nearest city
        int nearest = -1;
        double minDistance = numeric_limits<double>::max();
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distance(cities[path[i - 1]], cities[j]) < minDistance) {
                nearest = j;
                minDistance = distance(cities[path[i - 1]], cities[j]);
            }
        }

        // Adding the nearest city to the route
        path[i] = nearest;
        visited[nearest] = true;
    }

    return path;
}

// Function for route output
void printPath(vector<int>& path, vector<City>& cities) {
    int n = path.size();
    cout << "Route: ";
    for (int i = 0; i < n; i++) {
        cout << "(" << cities[path[i]].x << ", " << cities[path[i]].y << ") ";
    }
    cout << endl;
}

int main() {
    // Setting the coordinates of the cities
    vector<City> cities = {
        {1, 1},
        {2, 3},
        {4, 2},
        {5, 4},
        {3, 5}
    };

    // Solving the traveling salesman problem using the nearest neighbor method
    vector<int> path = nearestNeighbor(cities);

    // Output the route
    printPath(path, cities);

    return 0;
}