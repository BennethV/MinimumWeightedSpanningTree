/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file Node.h
 * @Synopsis Vertex implementation file (a node with a list of connected edges)
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */

#include <stdio.h>
#include "Vertex.h"

Vertex::Vertex(){
}
Vertex::~Vertex(){
    connectedEdges.clear();
}
