/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Node.h
 * @Synopsis Vertex class definition file with Struct edge definition
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */

#ifndef Vertex_h
#define Vertex_h

#include <stdio.h>
#include <vector>

struct Edge;

/* Vertex contains a weighting and endpoints (vertices or null) */
class Vertex{
public:
    Vertex();
    ~Vertex();

private:
    std::vector<Edge> connectedEdges;
};

/* Edge contains a weighting and endpoints (vertices or null) */
struct Edge{
    int weight;
    Vertex* u;
    Vertex* v;
};

#endif /* Node_h */
