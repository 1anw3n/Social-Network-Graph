#include "graph.h"

Graph::Graph() {}

void Graph::checkComponent() {
    bool visited[100] = {false};
    for (int i = 0; i < 100; i++) {
        while (!visited[i]) {
            Component c;
            dfs(c, visited, i);
            cp.push_back(c);
            visited[i] = true;
        }
    }
}

void Graph::dfs(Component &c, bool visited[], int v) {
    visited[v] = true;
    for (size_t a = 0; a < adjList[v].size(); a++) {
        int w = adjList[v].at(a).first;
        if (!visited[w]) {
            visited[w] = true;
            c.c.emplace(w, adjList[w]);
            dfs(c, visited, w);
        }
    }
}