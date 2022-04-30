//
// Created by herrerpm on 18/03/2022.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

/*
 * This header file adds imports two clases, the Node class and the Linked List class
 * the linked list allows for the creation of a resizible array that is based of on
 * the Node class, that counts with a Data and Next atributes for connecting the
 * list together.
 */

#include <iostream>

//Creates a node class that contains data and a pointer to another node
template <class Type>
class Node{
public:
    Node *Next;
    Type Data;
    Node(Type data, Node *next_item = nullptr);
    // The print method prints the data in a node
    void Print();
};

//Creates a Linked list class, that allows for content to be dynamically added
template <class Type>
class Linked_list{
public:
    Node<Type> *Head;
    Node<Type> *Last_node;
    int Length;
    bool Is_head = false;

    Linked_list();

    //The append function adds a node to the list, and takes the data as parameter
    void Append(Type data);

    //The PrintAll method iterates all over the list and prints each node's data
    void PrintAll() const;

    //The Node_Address method returns the pointer to a node based on it's position
    Node<Type>* Node_address(int node_number);

    //The Node_Address modifies the pointer of a node's data
    void Modify(int node_number, Type data);

    //The Remove method removes a node from the list based on it's position
    void Remove(int node_number);
};

#endif //LINKED_LIST_LINKEDLIST_H
