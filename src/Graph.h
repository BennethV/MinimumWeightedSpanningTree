/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Graph.h
 * @Synopsis Definition file for a Graph class
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

class Graph{
public:
    Graph();
    //Graph(const Graph& obj);
    bool isEmpty();
    long int numVertices();
    long int numEdges();
    void addVertex();
    void addEdge(int vert1, int ver2, double weight);
    void removeEdge(int i);
    bool isConnected(int vert1, int vert2);
    Edge* getEdge(int i);
    Vertex* getVertex(int i);
    void sortEdges();
    void display();
    ~Graph();
private:
    std::vector<Vertex*> vertices;
    std::vector<Edge*> edges;
    //int id_counter;
};

#endif /* Graph_h */
