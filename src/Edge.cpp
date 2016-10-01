/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Edge.h
 * @Synopsis Edge class Implementation file
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */

#include "Edge.h"

Edge::Edge(Vertex* vert1, Vertex* vert2, double w){
    u = vert1;
    v = vert2;
    weight = w;
    visited = 0;
};

bool Edge::isVisited(){
    return visited;
};

void Edge::setVisited(bool value){
    visited = value;
};

double Edge::getWeight(){
    return weight;
};

Vertex* Edge::getU(){
    return u;
};

Vertex* Edge::getV(){
    return v;
};

Edge::~Edge(){
    //destructor method: note that pointer still may exist in Graph.edges vector!
};
