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
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

using namespace std;

int main(void){

    LinkList* data= new LinkList();
    data->queue(1);
    data->queue(2);
    cout<< *data;
    cout << endl;
    data->dequeue();
    data->queue(3);
    data->queue(4);
    cout<< *data;
    cout << endl;
    data->dequeue();
    cout<< *data;
    cout << endl;
    Graph* g = new Graph;
    delete data;
    delete g;
    return 0;
}




