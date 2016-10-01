/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Edge.h
 * @Synopsis Edge class definition file
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */

#ifndef Edge_h
#define Edge_h

#include <stdio.h>
#include "Vertex.h"

/* Edge contains a weighting and endpoints (vertices or null) */
class Edge{
public:
    Edge(Vertex* vert1, Vertex* vert2, double w);
    bool isVisited();
    void setVisited(bool value);
    double getWeight();
    Vertex* getU();
    Vertex* getV();
    ~Edge();
private:
    double weight;
    Vertex* u;
    Vertex* v;
    bool visited;
};

#endif /* Edge_h */
