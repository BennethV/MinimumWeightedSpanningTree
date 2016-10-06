/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Graph_list.h
 * @Synopsis Definition file for a Graph_list class
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
 * @version 1.0
 * @date 2016-09-28
 */

#ifndef Graph_list_h
#define Graph_list_h

#include <stdio.h>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

class Graph_list{
public:
    Graph_list();
    //Graph_list(const Graph_list& obj);
    bool isEmpty();
    long int numVertices();
    long int numEdges();
    void addVertex();
    void addEdge(int vert1, int ver2, double weight);
    void removeEdge(long int i);
    bool isConnected(int vert1, int vert2);
    Edge* getEdge(long int i);
    Vertex* getVertex(long int i);
    void sortEdges();
    void display();
    ~Graph_list();
private:
    std::vector<Vertex*> vertices;
    std::vector<Edge*> edges;
    //int id_counter;
};

#endif /* Graph_list_h */
