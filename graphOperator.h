#ifndef GRAPHOPERATOR_H
#define GRAPHOPERATOR_H

#include "graphGenerator.h"
#include "graph.h"

//pass graph by reference
//pass component as parameter instead?

class GraphOperator{
    public:
        //Find the average degree [and the vertex with the highest degree????]
        double FindAverageDegree(Graph g);
        //Find the vertex with the highest degree
        double FindHighestDegree(Graph g);
        //Find the number of connected components
        int FindConnectedNumber(Graph g);
        //Find the diameter, radius, and centers of each component.
        void FindConnectedParameter(Component c);
        //Find the ratio between the number of open and closed triangles
        double FindTrianglesRatio();
        //Find the closest node from x with an interest level of 
        //at least t on hobby h.
        int FindClosestNode();
        //Find a person with the highest interest in h.
        double FindHighestInterest(int h);
        //Find a pair of nodes x and y whose ratio between hobby 
        //distance and graph distance is smallest.
        double FindDistanceRatio();

        //....

        //int countDegree();
        //double calcEccentricity();

    private: //?

};

#endif