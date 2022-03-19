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

//Creates a node class that contains data and a pointer to another node
template <class Type>
class Node{
public:
    Node *Next;
    Type Data;
    explicit Node(Type data, Node *next_item = nullptr){
        Data = data;
        Next = next_item;
    }
    // The print method prints the data in a node
    void Print(){
        std::cout << Data << "\n";
    }
};

//Creates a Linked list class, that allows for content to be dynamically added
template <class Type>
class Linked_list{
public:
    Node<Type> *Head;
    Node<Type> *Last_node;
    int Length;
    bool Is_head = false;

    Linked_list(){
        Head = nullptr;
        Last_node = nullptr;
        Length = 0;

    }

    //The append function adds a node to the list, and takes the data as parameter
    void Append(Type data){
        auto *ptr = new Node<Type>(data);
        if(!Is_head){
            Head = ptr;
            Last_node = ptr;
            Length += 1;
            Is_head = true;
        }
        else{
            Last_node -> Next = ptr;
            Last_node = ptr;
            Length += 1;
        }

    }

    //The PrintAll method iterates all over the list and prints each node's data
    void PrintAll() const{
        Node<Type> *ptr = Head;
        bool start = true;
        int count = 0;
        while(start){
            count += 1;
            std::cout << count << ")";
            ptr->Print();
            if(ptr->Next == nullptr){
                start = false;
            }
            else{
                ptr = ptr->Next;
            }
        }
    }

    //The Node_Address method returns the pointer to a node based on it's position
    Node<Type>* Node_Address(int node_number){
        Node<Type> *ptr = Head;
        for(int i = 1; i < node_number; i++){
            if(ptr->Next == nullptr){
                return nullptr;
            }
            else{
                ptr = ptr->Next;
            }
        }
        return ptr;
    }

    //The Node_Address modifies the pointer of a node's data
    void Modify(int node_number, Type data){
        Node<Type> *ptr = Node_address(node_number);
        ptr -> Data = data;
    }

    //The Remove method removes a node from the list based on it's position
    void Remove(int node_number){
        if(node_number == 1){
            Head = Head->Next;
        }
        else if(node_number == Length){
            Node<Type> *last_node = Node_address(Length - 1);
            last_node -> Next = nullptr;
        }
        else{
            Node<Type> *previous_node = Node_address(node_number - 1);
            Node<Type> *after_node = Node_address(node_number + 1);
            previous_node->Next = after_node;
        }
    }
};

#endif //LINKED_LIST_LINKEDLIST_H
