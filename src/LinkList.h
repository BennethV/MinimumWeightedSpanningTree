/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file LinkList.h
 * @Synopsis Definition file for a doubly linked-list
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
 * @version 1.0
 * @date 2016-09-28
 */

#ifndef LinkList_h
#define LinkList_h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


/* Node contains a weighting and endpoints (vertices or null) */
struct Node{
    int weight;
    Node* u;
};

class LinkList{
public:
    LinkList();
    bool isEmpty() const;
    const Node* front() const;
    const Node* rear() const;
    int getSize() const;
    void queue(const int& a);
    void dequeue();
    friend std::ostream& operator<<(std::ostream& out, const LinkList& obj);
    ~LinkList();

private:
    Node* head;
    Node* tail;
    int size;
};


#endif /* LinkList_h */
