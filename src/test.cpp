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

using namespace std;

int main(void){

    LinkList* data= new LinkList();
    data->add(1);
    data->add(2);
    cout<< *data;
    cout << endl;
    data->remove();
    data->add(3);
    data->add(4);
    cout<< *data;
    cout << endl;
    data->remove();
    cout<< *data;
    cout << endl;
    return 0;
}




