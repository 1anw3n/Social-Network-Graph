#ifndef COMPONENT_H
#define COMPONENT_H

#include <unordered_map>
#include <vector>
using edges = std::vector< std::pair<int, float> >;

class Component {
    public:
        // an unordered_map of vectors of pairs
        // each key represents a vertex
        // each value is a vector of edges of a vertex
        // pair.first is the vertex's neighbor, pair.second is the weight
        std::unordered_map<int, edges> c;


        Component();

        // returns a vector with all the centers in a component
        std::vector<int> center();

		// performs depth first search; helper function
		void dfs(float distance[], int v);

        // returns the diameter of the component
        float diameter();

        // returns the eccentricity of a vertex
        float eccentricity(int v);

        // returns the radius of the component
        float radius();
};

#endif