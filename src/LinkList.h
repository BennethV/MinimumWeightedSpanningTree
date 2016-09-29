/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file LinkList.h
 * @Synopsis Definition file for a doubly linked-list
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-28
 */


#ifndef LinkedList

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

/* edge contains a weighting and endpoints (vertices or null) */
struct Edge{
    int weight;
    Edge* u;
    Edge* v;
};


class LinkList{
public:
    LinkList();
    bool isEmpty() const;
    const Edge* front() const;
    const Edge* rear() const;
    int getSize() const;
    void add(const int& a);
    void remove();
    friend std::ostream& operator<<(std::ostream& out, const LinkList& obj);
    ~LinkList();

private:
    Edge* head;
    Edge* tail;
    int listSize;
};

#define LinkList_h

#endif /* LinkList_h */
