/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file LinkList.cpp
 * @Synopsis Implentation file for doubly linked-list
 * @author Tyson Cross, Kopano Malombo, Vulombe Mathebula, Kimita Ramalingum, Vassiliki Marantos, Mfaniseni Thusi, Kulani Nukeri
 * @version 1.0
 * @date 2016-09-27
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*
 Implementation of a linked list. The programmer using these methods needs to
 be cautious about checking if the list isEmpty(), and throw an exception if an
 empty list uses remove(), or is the front() or rear() methods are
 used on an empty stack. These latter two methods return the memory address of
 the head and tail, respectively.
*/

LinkList::LinkList(){
    head = NULL;
    tail = NULL;
    size = 0;
}
LinkList::~LinkList(){
    while (!isEmpty()) remove();
    delete head;
    delete tail;
}
bool LinkList::isEmpty() const{
    return (head == NULL);
}

const Edge* LinkList::front() const{
    if(!isEmpty()) return head;
    else throw std::runtime_error("List is empty!");
}

const Edge* LinkList::rear() const{
    if(!isEmpty()) return tail;
    else throw std::runtime_error("List is empty!");
}

int LinkList::getSize() const{
    return size;
}

void LinkList::add(const int& a){
    Edge* newEdge = new Edge();
    newEdge->weight = a;
    if(size==0) {
        head = newEdge;
        tail = newEdge;
    } else {
        tail->u = newEdge;
        tail = newEdge;
    }
    size ++;
}

void LinkList::remove(){
    if(isEmpty()) throw std::runtime_error("List is empty!");
    else {
        Edge* temp = new Edge();
        temp = head;
        if(head->u == NULL){ //||(head->v == NULL)) {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        else {
            head = head->u;
            size --;
        }
    delete temp;
    }
}

std::ostream& operator<<(std::ostream& out, const LinkList& obj){
        Edge* position = obj.head;
        out << "{ ";
        while(position != NULL){
            out << position->weight << " ";
            position=position->u;
        }
        out << "}";
    return out;
}
