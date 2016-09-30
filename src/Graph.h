/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Graph.h
 * @Synopsis Definition file for a graph ADT
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <vector>
#include "Vertex.h"

class Graph{
public:
    Graph();
    int size();
    bool isEmpty();
    void addVertex(Vertex* vert);
    void addEdge(Vertex* node1, Vertex* node2, double weight);
    void removeVertex();
    void removeEdge();
    ~Graph();
private:
};


#endif /* Graph_h */
