/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Vertex.cpp
 * @Synopsis Vertex class implementation file
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */

#include <stdio.h>
#include "Vertex.h"

Vertex::Vertex(){
    visited = 0;
}

void Vertex::addEdge(Edge* e){

};

void Vertex::removeEdge(Edge* e){

};

const bool Vertex::isVisited(){
    return visited;
};

void Vertex::setVisited(){

};

Vertex::~Vertex(){
    connectedEdges.clear();
}
