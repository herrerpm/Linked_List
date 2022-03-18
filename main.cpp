#include <iostream>

using std::cout;

template <class Type>
class Node{
public:
    Node *Next;
    Type Data;
    explicit Node(Type data, Node *next_item = nullptr){
        Data = data;
        Next = next_item;
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

    void Print() const{
        Node<Type> *ptr = Head;
        bool start = true;
        int count = 0;
        while(start){
            count += 1;
            cout << count << ")";
            cout << ptr -> Data << "\n";
            if(ptr->Next == nullptr){
                start = false;
            }
            else{
                ptr = ptr->Next;
            }
        }
    }

    void Print_node(Node<Type> *ptr){
        cout << ptr -> Data << "\n";
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


    Node<Type>* Modify_node(int node_number, Type data){
        Node<Type> *ptr = Node_address(node_number);
        ptr -> Data = data;
        return ptr;
    }

    void Remove_node(int node_number){
        Node<Type> *ptr = Head;
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


int main(){
    Linked_list<int> list = Linked_list<int>();
    for(int i = 0; i < 4; i++){
        list.Append(i);
    }
    cout << "List data \n\n";
    list.Print();
    cout << "\nRemove third node \n\n";
    list.Remove_node(3);
    list.Print();
    cout << "\nModify second node \n\n";
    list.Modify_node(2,100);
    list.Print();
    cout << "\nPrint single node value \n\n";
    list.Print_node(list.Node_address(3));

}
