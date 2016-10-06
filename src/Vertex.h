/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Vertex.h
 * @Synopsis Vertex class definition file
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
 * @version 1.0
 * @date 2016-09-28
 */

#ifndef Vertex_h
#define Vertex_h

#include <stdio.h>
#include <vector>
#include "Edge.h"

class Edge; // Forward declaration

/* Vertex contains a weighting and endpoints (vertices or null) */
class Vertex{
public:
    Vertex(long int i);
    void addEdge(Edge* e);
    void removeEdge(Edge* e);
    Edge* getEdge(int i);
    long int getName();
    long int numEdges();
    const bool isVisited();
    void setVisited(bool value);
    ~Vertex();
private:
    bool visited;
    long int name;
    std::vector<Edge*> connectedEdges;
};

#endif /* Vertex_h */
