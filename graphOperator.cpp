#include "graphOperator.h"

float GraphOperator::FindAverageDegree(){
    //stub
    int vertices;
    int totalDeg = countDegree();
    int averageDeg = totalDeg / vertices;
}

float GraphOperator::FindHighestDegree(){
    int vertices;
    int max;
    for(int i = 0; i < vertices; i++){
        if(){ //if current degree higher than prev
            //max == new degree
            //stub
        }
    }
    return max;
}

int GraphOperator::FindConnectedNumber(){
    //stub
}

void GraphOperator::FindConnectedParameter(){
    
}

float GraphOperator::FindTrianglesRatio(){

}

int GraphOperator::FindClosestNode(){
    
}

float GraphOperator::FindHighestInterest(){
    
}

float GraphOperator::FindDistanceRatio(){

}

//not required helper functions:

int GraphOperator::countDegree(){
    
}

float GraphOperator::calcEccentricity(){
    
}