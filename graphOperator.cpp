#include "graphOperator.h"
#include "graph.h"

double GraphOperator::FindAverageDegree(Graph g) {
    int totalDeg = 0;
    
    for(int i = 1; i < NUM_VERTEX; i++) {
        totalDeg += g.degree(i);
    }
    
    return totalDeg / NUM_VERTEX;
}

double GraphOperator::FindHighestDegree(Graph g) {
    int max = 0;
    
    for(int i = 0; i < NUM_VERTEX; i++) {
        int deg = g.degree(i);
        if(max < deg){
            max = deg;
        }
    }
    return max;
}

int GraphOperator::FindConnectedNumber(Graph g) { 
    return g.cp.size();
}

void GraphOperator::FindConnectedParameter(Component c) {
    // 1 digit after decimal point, fix later
    double diameter = c.diameter();
    double radius = c.radius();
    std::vector<int> center = c.center();

    cout << diameter << ", " << radius << ", ";
    for(size_t i = 0; i < center.size(); i++){
        if(i != center.size() - 1){
            cout << center[i] << ", ";
        }
        else{
            cout << center[i];
        }
    }
}

double GraphOperator::FindTrianglesRatio(){

}

int GraphOperator::FindClosestNode(){
    
}

double GraphOperator::FindHighestInterest(int h){
    
}

double GraphOperator::FindDistanceRatio(){

}