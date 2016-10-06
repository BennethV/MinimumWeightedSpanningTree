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

    Graph_list* g = new Graph_list;
    g->addVertex();
    g->addVertex();
    g->addEdge(0, 1, int_random());
    g->addVertex();
    g->addVertex();
    g->addEdge(2, 3, int_random());
    g->addEdge(0, 3, int_random());
    g->addEdge(0, 2, int_random());
    g->display();
    g->addEdge(0, 2, int_random()); // will print cerr, but continue, without adding edge
    g->addVertex();
    g->display();
    g->removeEdge(g->numEdges()-1);
    // g->addEdge(1, 5, rand()%100 + 1); //Does not exist, throws an exception
    g->display();

    delete g;
    return 0;
}
