#include <algorithm>
#include <iterator>
#include <limits>
#include "component.h"

Component::Component() {}

std::vector<int> Component::center() {
	std::vector<int> out;
	return out;
}

void Component::dfs(float distance[], int v) {
    for (auto p : c.at(v)) {
        int w = p.first;
        float weighted = distance[v] + p.second;
        if (distance[w] > weighted) {
            distance[w] = weighted;
            dfs(distance, w);
        }
    }
}

float Component::diameter() {
    std::vector<float> maxDist;
    for (auto v : c) {
		float distance[100] = {0};
		dfs(distance, v.first);
		maxDist.push_back(*( std::max(std::begin(distance), std::end(distance)) ));
    }
    
    return *( std::max(std::begin(maxDist), std::end(maxDist)) );
}

// initializes an array of all 100 vertices, set all distances to 0
// loop through all adjacent vertices, find eccentricity of them using DFS
float Component::eccentricity(int v) {
    float distance[100] = {0};
    dfs(distance, v);

    return *(std::max(std::begin(distance), std::end(distance)));
}

float Component::radius() {
	return 420.0;
}