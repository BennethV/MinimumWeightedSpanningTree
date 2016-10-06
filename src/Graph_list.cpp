/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Graph_list.cpp
 * @Synopsis Implementation file for a Graph_list class
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
 * @version 1.0
 * @date 2016-09-28
 */
//

#include <iostream>
#include <algorithm>
#include "Graph_list.h"


Graph_list::Graph_list(){
};

//Graph_list::Graph_list(const Graph_list& obj){};

bool Graph_list::isEmpty(){
    return vertices.empty();
};

long int Graph_list::numVertices(){
    return vertices.size();
};

long int Graph_list::numEdges(){
    return edges.size();
};

void Graph_list::addVertex(){
    // make a new vertex, add it to the vertices list
    // need to check if vertex already exists??
    Vertex* vertex1 = new Vertex(vertices.size());
    vertices.push_back(vertex1);
};

void Graph_list::addEdge(int vert1, int vert2, double weight){
    // make a new edge, between the two indices of the vertices list, with specified weight
    // update the relevant vertices, to add this new edge to their connectedEdges list
    bool status = true;
    if ( (vert1>numVertices()) || (vert2>numVertices()) ) {
        throw std::out_of_range("Specified vertex does not exist (out of range), unable to addEdge()");
    };
    if (isConnected(vert1, vert2)) {
        std::cerr << "Warning : Vertices " << vertices.at(vert1)->getName() << " and " << vertices.at(vert2)->getName() << " are already connected, unable to addEdge()" << std::endl;
        status = false;
    }
    if (status==true){
        Edge* edge1 = new Edge(vertices.at(vert1), vertices.at(vert2), weight);
        edges.push_back(edge1);
        vertices.at(vert1)->addEdge(edge1);
        vertices.at(vert2)->addEdge(edge1);
    };
};

void Graph_list::removeEdge(long int i){
    // for the specified edge, remove the edge from the list of connected edges for both vertices
    // remove the specifed edge from the list of edges
    Edge* edge1 = edges.at(i);
    edge1->getU()->removeEdge(edge1);
    edge1->getV()->removeEdge(edge1);
    edges.erase(edges.begin()+i);
};

bool Graph_list::isConnected(int vert1, int vert2){
    // check the connectedEdges lists for both vertices, to see if there is a common edge
    for (int i = 0; i < vertices.at(vert1)->numEdges() ; i++){
        for (int j = 0; j < vertices.at(vert2)->numEdges() ; j++){
            if (vertices.at(vert1)->getEdge(i) == vertices.at(vert2)->getEdge(j)){
                return true;
            }
        }
    }
    return false;
};

Edge* Graph_list::getEdge(long int i){
    return edges.at(i);
};

Vertex* Graph_list::getVertex(long int i){
    return vertices.at(i);
};

void Graph_list::sortEdges(){
    // sort edges by weight, check each edge in the list for its weight
    // comparison operator < is overloaded to compare by weight
    std::sort(edges.begin(), edges.end());
};

void Graph_list::display(){
    std::cout << " Adjacency list: Vertex →Vertex(weight of edge) " << std::endl;
    for (int i =0; i< numVertices(); i++){
        Vertex* vertex1 = vertices.at(i);
        std::cout << i << ":  →";
        for (int j = 0 ; j < vertex1->numEdges(); j++){
            Edge* edge1 = vertex1->getEdge(j);
            Vertex* u = edge1->getU();
            Vertex* v = edge1->getV();
            if ((u != vertex1) && ( v != vertex1)){
                //throw exception
                std::cerr << "Warning : Vertex/edge mismatch at vertex index [" << i << "] with edge index [" << j << "]" << std::endl;
            }
            else if(u == vertex1){
                std::cout << v->getName();
                std::cout << "(" << edge1->getWeight() << ") ";
                }
            else if(v == vertex1){
                std::cout << u->getName();
                std::cout << "(" << edge1->getWeight() << ") ";
            }
            if (j+1!=vertex1->numEdges())
            std::cout << "  →";
            }
        std::cout << std::endl;
    }

//    std::cout << " Vertices connected by edges: " << std::endl;
//    for (int i =0; i< numEdges(); i++){

    // display the Graph_list
};

Graph_list::~Graph_list(){
    for (int i = 0; i < numEdges(); i++){
        delete edges.at(i);
    }
    for (int i = 0; i < numVertices(); i++){
        delete vertices.at(i);
    }
};
