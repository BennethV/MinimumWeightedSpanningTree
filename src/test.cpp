//
//  test.cpp
//  MaxSubArray test file
//
//  Created by Tyson on 2016/08/25.
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

using namespace std;

int main(void){

    LinkList* data= new LinkList();
    data->enqueue(1,1,2,3);
    data->enqueue(2,4,5,6);
    cout<< *data;
    cout << endl;
    data->dequeue();
    data->enqueue(3,7,8,9);
    data->enqueue(4,10,11,12);
    cout<< *data;
    cout << endl;
    data->dequeue();
    cout<< *data;
    cout << endl;
    return 0;
}




