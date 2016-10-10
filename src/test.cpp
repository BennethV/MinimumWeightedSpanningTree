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
//#include "Graph_matrix.h"

using namespace std;

int main(void){
    //srand(double(time(NULL)));

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
