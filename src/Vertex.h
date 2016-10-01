/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Vertex.h
 * @Synopsis Vertex class definition file
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */

#ifndef Vertex_h
#define Vertex_h

#include <stdio.h>
#include <vector>
#include "Edge.h"

/* Vertex contains a weighting and endpoints (vertices or null) */
class Vertex{
public:
    Vertex();
    void addEdge(Edge* e);
    void removeEdge(Edge* e);
    const bool isVisited();
    void setVisited();
    ~Vertex();
private:
    bool visited;
    std::vector<Edge*> connectedEdges;
};

#endif /* Vertex_h */
