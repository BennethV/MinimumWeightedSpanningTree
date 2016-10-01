/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Graph.cpp
 * @Synopsis Implementation file for a Graph class
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */
//

#include "Graph.h"

Graph::Graph(){
};

//Graph::Graph(const Graph& obj){};

bool Graph::isEmpty(){
    return vertices.empty();
};

long int Graph::numVertices(){
    return vertices.size();
};

long int Graph::numEdges(){
    return edges.size();
};

void Graph::addVertex(){
    // make a new vertex, add it to the vertices list
};

void Graph::addEdge(int vert1, int ver2, double weight){
    // make a new edge, between the two indices of the vertices list, with specified weight
    // update the relevant vertices to add thies edge to their connected Edges list
};

void Graph::removeEdge(int i){
    // for the specified edge, remove the edge from the list of connected dges for both vertices
    // remove the specifed edge from the list of edges
};

bool Graph::isConnected(int vert1, int vert2){
    // check the connectedEdges lists for both vertices, to see if there is a common edge
};

Edge* Graph::getEdge(int i){
    return edges.at(i);
};

Vertex* Graph::getVertex(int i){
    return vertices.at(i);
};

void Graph::sortEdges(){
    // sort edges by weight, check each edge in the list for its weight
};

void Graph::display(){
    // display the graph
};

Graph::~Graph(){
    for (int i = 0; i < numEdges(); i++){
        delete edges.at(i);
    }
    for (int i = 0; i < numVertices(); i++){
        delete vertices.at(i);
    }
};
