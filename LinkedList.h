//
// Created by mherr on 18/03/2022.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H
template <class Type>
class Node{
public:
    Node *Next;
    Type Data;
    explicit Node(Type data, Node *next_item = nullptr){
        Data = data;
        Next = next_item;
    }

    void Print(){
        std::cout << Data << "\n";
    }
};

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

    void Print_node(Node<Type> *ptr){
        std::cout << ptr -> Data << "\n";
    }

    Node<Type>* Node_address(int node_number){
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


    Node<Type>* Modify(int node_number, Type data){
        Node<Type> *ptr = Node_address(node_number);
        ptr -> Data = data;
        return ptr;
    }

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
