#include <string>
#include "graphGenerator.h"

GraphGenerator::GraphGenerator(std::ifstream &file, Graph &g) {
    int n1, n2, u, v, len;
    double weight;
    std::string s;
    
    while (!file.eof()) {
        std::getline(file, s);
        if (s.empty()) break;
        n1 = s.find(",");
        n2 = s.rfind(",");
        len = s.length();
        u = stoi(s.substr(0, n1));
        v = stoi(s.substr(n1+1, n2-n1-1));
        weight = stof(s.substr(n2+1, len-n2-1));
        addEdge(g, u, v, weight);
    }

    g.checkComponent();
}

void GraphGenerator::addEdge(Graph &g, int u, int v, double w) {
    g.adjList.at(u).push_back(std::make_pair(v, w));
    g.adjList.at(v).push_back(std::make_pair(u, w));
}