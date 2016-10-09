//
//  test.cpp
//  MaxSubArray test file
//
//  Created by Tyson on 2016/9/27.
//  Copyright © 2016 Tyson Cross. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "LinkList.h"
#include "Graph_list.h"

double float_random(){
    return (double)rand() / RAND_MAX;
};

double int_random(){
    return rand()%100 +1;
}
using namespace std;

int main(void){
    srand(double(time(NULL)));

/*  Example code below, manually constructing a graph object
//    Graph_list* g = new Graph_list;
//    g->addVertex();
//    g->addVertex();
//    g->addEdge(0, 1, int_random());
//    g->addVertex();
//    g->addVertex();
//    g->addEdge(2, 3, int_random());
//    g->addEdge(0, 3, int_random());
//    g->addEdge(0, 2, int_random());
//    g->display();
//    g->addEdge(0, 2, int_random()); // will print cerr, but continue, without adding edge
//    g->addVertex();
//    g->display();
//    g->removeEdge(g->numEdges()-1);
//    // g->addEdge(1, 5, int_random()); //Does not exist, throws an exception
//    g->display();
 */

    //const string fileInName = "../../data/sparse.dat";
    const string fileInName = "../../data/dense.dat";

    ifstream input(fileInName, ios::in);

    // error checking
    if (!input.is_open()) { cout << "Unable to open file:" << fileInName << endl; return -1;}

    string line;
    int numVertex, numEdge, vert1, vert2;
    long int linesCount = 0;
    double weight;

    // Get no. of lines in the file.
    while (getline(input, line)) linesCount++;
    input.clear();
    input.seekg(0, ios::beg);

    // read in an build graph, while data to read
    while (linesCount>1) {
        getline(input, line);
        istringstream ss_1(line);
        ss_1 >> numVertex;
        linesCount--;
        getline(input, line);
        istringstream ss_2(line);
        ss_2 >> numEdge;
        linesCount--;

        Graph_list* g = new Graph_list;

        for (int i = 0; i < numVertex; i++) g->addVertex();
        for (int i = 0; i < numEdge; i++) {
            getline(input, line);
            linesCount--;
            istringstream ss(line);
            ss >> vert1 >> vert2 >> weight;
            //std::cout << vert1 << "→" << vert2 << "(" << weight << ")" << std::endl;
            g->addEdge(vert1, vert2, weight);
        };

        // Do something with the graph here....
        g->display();

        delete g;
    };

    input.close();
    return 0;
}
