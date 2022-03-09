#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include <fstream>
#include "graph.h"

class GraphGenerator {
    public:
        GraphGenerator(std::ifstream &file, Graph &g);
        void addEdge(Graph &g, int u, int v, double w);
};

#endif