/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Graph.cpp
 * @Synopsis Implementation file for a Graph class
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */
//

#include <iostream>
#include <algorithm>
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
    // need to check if vertex already exists??
    Vertex* vertex1 = new Vertex(vertices.size() + 1);
    vertices.push_back(vertex1);
};

void Graph::addEdge(int vert1, int vert2, double weight){
    // make a new edge, between the two indices of the vertices list, with specified weight
    // update the relevant vertices, to add this new edge to their connectedEdges list
    Vertex* vertex2 = vertices.at(vert2);
    Vertex* vertex1 = vertices.at(vert1);
    Edge* edge1 = new Edge(vertex1, vertex2, weight);
    vertex1->addEdge(edge1);
    vertex2->addEdge(edge1);
};

void Graph::removeEdge(int i){
    // for the specified edge, remove the edge from the list of connected edges for both vertices
    // remove the specifed edge from the list of edges
    Edge* edge1 = edges.at(i);
    edge1->getU()->removeEdge(edge1);
    edge1->getV()->removeEdge(edge1);
    edges.erase(edges.begin()+i);
};

bool Graph::isConnected(int vert1, int vert2){
    // check the connectedEdges lists for both vertices, to see if there is a common edge
    Vertex* vertex2 = vertices.at(vert2);
    Vertex* vertex1 = vertices.at(vert1);
    for (int i = 0; i < vertex1->numConnectedEdges() ; i++){
        Edge* edge1 = vertex1->getEdge(i);
        for (int j = 0; j < vertex2->numConnectedEdges() ; j++){
            if (edge1 == vertex2->getEdge(j)){
                return true;
            }
        }
    }
    return false;
};

Edge* Graph::getEdge(int i){
    return edges.at(i);
};

Vertex* Graph::getVertex(int i){
    return vertices.at(i);
};

void Graph::sortEdges(){
    // sort edges by weight, check each edge in the list for its weight
    // comparison operator < is overloaded to compare by weight
    std::sort(edges.begin(), edges.end());
};

void Graph::display(){
    std::cout << " Connected edges listed by wieghting, per vertex: " << std::endl;
    for (int i =0; i< numVertices(); i++){
        Vertex* vertex1 = vertices.at(i);
        std::cout << "{ ";
        std::cout << i << " → ";
        for (int j = 0 ; j< vertex1->numConnectedEdges(); j++){
            Edge* edge1 = vertex1->getEdge(j);
            Vertex* u = edge1->getU();
            Vertex* v = edge1->getV();
            if ((u != vertex1) && ( v != vertex1)){
                //throw exception
                std::cerr << "Warning : Vertex/edge mismatch at vertex index [" << i << "] with edge index [" << j << "]" << std::endl;
            }
            else if(u == vertex1){
                std::cout << "( " << edge1->getWeight() << ") → ";
                std::cout << v->getName();
                }
            else if(v == vertex1){
                std::cout << "( " << edge1->getWeight() << ") → ";
                std::cout << u->getName();
            }
            if (j+1!=vertex1->numConnectedEdges())
            std::cout << " → ";
            }
        std::cout << " }" << std::endl;
    }

//    std::cout << " Vertices connected by edges: " << std::endl;
//    for (int i =0; i< numEdges(); i++){

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
