#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

#include "graphOperator.h"

GraphOperator::GraphOperator(Graph gr) {
    g = gr;
}

//Find the average degree
double GraphOperator::FindAverageDegree() {
    double totalDeg = 0;
    
    for (size_t i = 1; i < g.adjList.size(); i++) {
        totalDeg += g.degree(i);
    }
    
    return totalDeg / (g.adjList.size() - 1);
}

//Find the vertex with the highest degree
std::vector<int> GraphOperator::FindHighestDegree() {
    std::vector<int> max;
    int deg = g.degree(1);
    
    for (size_t i = 1; i < g.adjList.size(); i++) {
        if (deg < g.degree(i)) {
            deg = g.degree(i);
            max.clear();
        }
        if (deg == g.degree(i)) max.push_back(i);
    }
    
    return max;
}

//Find the number of connected components
int GraphOperator::FindConnectedNumber() { 
    return g.cp.size();
}

//Find the diameter, radius, and centers of each component.
void GraphOperator::FindConnectedParameter(Component c) {
    // 1 digit after decimal point, fix later <-- fixed?
    double diameter = c.diameter();
    double radius = c.radius();
    std::vector<int> center = c.center();

    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(1) << diameter << ", " << radius << ", ";
    for (size_t i = 0; i < center.size(); i++){
        if (i != center.size() - 1){
            std::cout << center[i] << ", ";
        } else {
            std::cout << center[i];
        }
    }
}

//Find the ratio between the number of open and closed triangles
double GraphOperator::FindTrianglesRatio(){
    double openTriangle = g.totalOpenTriangles();
    double closedTriangle = g.totalClosedTriangles();

	return openTriangle / closedTriangle; //check which should be num and denom
}

// uses Dijkstra's algorithm to first fill the list of distances from vertex x
// and find the closest node with enough interest t in hobbies h
int GraphOperator::FindClosestNode(int x, double t, int h){
    if (g.hobbies[x][h] >= t) return x;

    // Dijkstra
    double distance[g.adjList.size()];
    std::fill_n(distance, g.adjList.size(), std::numeric_limits<double>::infinity());
    distance[x] = 0;
    std::vector<int> visited;
    std::vector<int> vertices;
    for (size_t i = 1; i < g.adjList.size(); i++) {vertices.push_back(i);}
    int u;
    while (!vertices.empty()) {
        double min = std::numeric_limits<double>::infinity();
        std::vector<int>::iterator index;
        for (auto i = vertices.begin(); i != vertices.end(); i++) {
            if (distance[*i] < min) {
                u = *i;
                min = distance[*i];
                index = i;
            }
        }
        visited.push_back(u);
        vertices.erase(index);
        for (auto e : g.adjList.at(u)) {
            if (distance[e.first] > (distance[u] + e.second)) distance[e.first] = (distance[u] + e.second);
        }
    }

    // finding the vertex of minimum distance, check if it has enough interest
    // if no then pop the distance in order to find the next minimum
    while (!visited.empty()) {
        int min = 0;
        std::vector<int>::iterator index;
        for (auto i = visited.begin(); i != visited.end(); i++) {
            if (distance[*i] < distance[min]) {
                min = *i;
                index = i;
            }
        }
        if (g.hobbies[min][h] >= t) return min;
        visited.erase(index);
    }
    return -1;
}

//Find a person with the highest interest in h.
int GraphOperator::FindHighestInterest(int h) {
    double highest = 0;
    int person = 0;
    for (size_t i = 1; i < g.adjList.size(); i++) {
        if (g.hobbies[i][h] > highest) {
            highest = g.hobbies[i][h];
            person = i;
        }
    }
    return person;
}

//check ratio
//Find a pair of nodes x and y whose ratio between hobby 
        //distance and graph distance is smallest.
void GraphOperator::FindDistanceRatio() {
    int x, y = 0;
    double minRatio = 1;
        
    for(size_t i = 1; i < g.adjList.size(); i++) {
        for(auto edge : g.adjList.at(i)) {
            double hobdist = hobbyDistance(i, edge.first);
            double dist = edge.second;
            double temp = hobdist / dist;
            if(temp < minRatio) {
                minRatio = temp;
                x = i;
                y = edge.first;
            }
        }
    }
    
    std::cout << x << ", " << y << std::endl;
}

double GraphOperator::hobbyDistance(int x, int y) {
    double hd = 0;
    double temp = 0;
    for(int j = 1; j < 21; j++){
        temp += pow((g.hobbies[x][j] - g.hobbies[y][j]), 2);       
    }
    
    hd = sqrt(temp);
    return hd;
}