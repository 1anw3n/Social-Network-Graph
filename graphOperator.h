#ifndef GRAPHOPERATOR_H
#define GRAPHOPERATOR_H

#include "graphGenerator.h"
#include "graph.h"

//pass graph by reference

class GraphOperator{
    public:
        //Find the average degree [and the vertex with the highest degree????]
        float FindAverageDegree();
        //Find the vertex with the highest degree
        float FindHighestDegree();
        //Find the number of connected components
        int FindConnectedNumber();
        //Find the diameter, radius, and centers of each component.
        void FindConnectedParameter();
        //Find the ratio between the number of open and closed triangles
        float FindTrianglesRatio();
        //Find the closest node from x with an interest level of 
        //at least t on hobby h.
        int FindClosestNode();
        //Find a person with the highest interest in h.
        float FindHighestInterest();
        //Find a pair of nodes x and y whose ratio between hobby 
        //distance and graph distance is smallest.
        float FindDistanceRatio();

        //....

        int countDegree();
        float calcEccentricity();

    private: //?

};

#endif