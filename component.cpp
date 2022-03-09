#include <algorithm>
#include <iterator>
#include <limits>
#include "component.h"

// may need to change to doubles instead of floats (check discord)

Component::Component() {}

Component::Component(const Component &comp) {
    for (auto m : comp.c) {
        c.emplace(m.first, m.second);
    }
}

//set of nodes w eccentricity equal to the radius of the graph (could be more than one)
std::vector<int> Component::center() {
    std::vector<int> out;
    
    std::vector<double> minEccen;
    for(auto p : c) {
        double eccen = eccentricity(p.first);
        minEccen.push_back(eccen);
    }

	double radius = *( std::min(minEccen.begin(), minEccen.end()) );
    
    for(size_t i = 0; i < minEccen.size(); i++) {
        if(minEccen[i] == radius){
            out.push_back(i);
        }
    }
    
	return out;
}

void Component::dfs(double distance[], int v) {
    for (auto p : c.at(v)) {
        int w = p.first;
        double weighted = distance[v] + p.second;
        if (distance[w] > weighted) {
            distance[w] = weighted;
            dfs(distance, w);
        }
    }
}

//max eccentricity
double Component::diameter() {
    std::vector<double> maxEccen;
    for (auto p : c) {
        double eccen = eccentricity(p.first);
        maxEccen.push_back(eccen);
    }
    
    return *( std::max(maxEccen.begin(), maxEccen.end()) );
}

// initializes an array of all 100 vertices, set all distances to 0
// loop through all adjacent vertices, find eccentricity of them using DFS
double Component::eccentricity(int v) {
    double distance[NUM_VERTEX] = {0};
    dfs(distance, v);

    return *(std::max(std::begin(distance), std::end(distance)));
}

//min eccentricity
double Component::radius() {
    std::vector<double> minEccen;
    for(auto p : c) {
        double eccen = eccentricity(p.first);
        minEccen.push_back(eccen);
    }

	return *( std::min(minEccen.begin(), minEccen.end()) );
}