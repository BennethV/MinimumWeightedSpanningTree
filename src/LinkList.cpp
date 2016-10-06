/**
 * COMS2004 Assignment 2, Minimum Weighted Spanning Tree Project
 * @file LinkList.cpp
 * @Synopsis Implentation file for doubly linked-list
 * @author Tyson Cross, Kulani Nukeri, Kopano Malombo, Vassiliki Marantos, Vulombe Mathebula, Kimita Ramalingum, Mfaniseni Thusi
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
 empty list uses dequeue(), or is the front() or rear() methods are
 used on an empty stack. These latter two methods return the memory address of
 the head and tail, respectively.
*/

LinkList::LinkList(){
    head = NULL;
    tail = NULL;
    size = 0;
}
LinkList::~LinkList(){
    while (!isEmpty()) dequeue();
    delete head;
    delete tail;
}
bool LinkList::isEmpty() const{
    return (head == NULL);
}

const Node* LinkList::front() const{
    if(!isEmpty()) return head;
    else throw std::runtime_error("List is empty!");
}

const Node* LinkList::rear() const{
    if(!isEmpty()) return tail;
    else throw std::runtime_error("List is empty!");
}

int LinkList::getSize() const{
    return size;
}

void LinkList::queue(const int& a){
    Node* newNode = new Node();
    newNode->weight = a;
    if(size==0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->u = newNode;
        tail = newNode;
    }
    size ++;
}

void LinkList::dequeue(){
    if(isEmpty()) throw std::runtime_error("List is empty!");
    else {
        Node* temp = new Node();
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
        Node* position = obj.head;
        out << "{ ";
        while(position != NULL){
            out << position->weight << " ";
            position=position->u;
        }
        out << "}";
    return out;
}
