#include "graph.h"

Graph::Graph() {
    adjList.resize(NUM_VERTEX);
}

void Graph::checkComponent() {
    bool visited[NUM_VERTEX] = {false};
    for (int i = 1; i < NUM_VERTEX; i++) {
        if (visited[i]) continue;
        
        visited[i] = true;
        Component c;
        c.c.emplace(i, adjList.at(i));
        dfs(c, visited, i);
        cp.push_back(c);
    }
}

int Graph::degree(int v) {
    return adjList.at(v).size();
}

void Graph::dfs(Component &comp, bool visited[], int v) {
    visited[v] = true;
    for (size_t a = 0; a < adjList.at(v).size(); a++) {
        int w = adjList.at(v).at(a).first;
        if (visited[w]) continue;
        
        visited[w] = true;
        comp.c.emplace(w, adjList.at(w));
        dfs(comp, visited, w);
    }
}