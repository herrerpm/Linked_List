#include "LinkedList.h"

template <class Type>
Node<Type>::Node(Type data, Node<Type> *next_item){
    Data = data;
    Next = next_item;
}

template <class Type>
void Node<Type>::Print(){
    std::cout << Data << "\n";
}

template <class Type>
Linked_list<Type>::Linked_list() {
    Head = nullptr;
    Last_node = nullptr;
    Length = 0;
}

template <class Type>
void Linked_list<Type>::Append(Type data){
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

template <class Type>
void Linked_list<Type>::PrintAll() const{
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

template <class Type>
Node<Type>* Linked_list<Type>::Node_address(int node_number){
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

template <class Type>
void Linked_list<Type>::Remove(int node_number){
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