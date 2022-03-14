#include <iostream>

using std::cout;

class Node{
public:
    Node *Next;
    int Data;
    explicit Node(int data, Node *next_item = nullptr){
        Data = data;
        Next = next_item;
    }
};

class Linked_list{
public:
    Node *Head;
    Node *Last_node;
    int Lenght;
    bool Is_head = false;

    Linked_list(){
        Head = nullptr;
        Last_node = nullptr;
        Lenght = 0;

    }

    void Add_head(class Node *node){
        Head = node;
        Last_node = node;
        Lenght += 1;
        Is_head = true;
    }


    void Add_node(class Node *node){
        Last_node -> Next = node;
        Last_node = node;
        Lenght += 1;
    }

    void Print() const{
        Node *ptr = Head;
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

    void Print_node(Node *ptr){
        cout << ptr -> Data << "\n";
    }

    Node* Node_address(int node_number){
        Node *ptr = Head;
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


    Node* Modify_node(int node_number, int data){
        Node *ptr = Node_address(node_number);
        ptr -> Data = data;
        return ptr;
    }

    void Remove_node(int node_number){
        Node *ptr = Head;
        if(node_number == 1){
            Head = Head->Next;
        }
        else if(node_number == Lenght){
            Node *last_node = Node_address(Lenght - 1);
            last_node -> Next = nullptr;
        }
        else{
            Node *previous_node = Node_address(node_number - 1);
            Node *after_node = Node_address(node_number + 1);
            previous_node->Next = after_node;
        }
    }
};


int main(){
    Linked_list list = Linked_list();
    list.Add_head(new Node(7));
    for(int i = 0; i < 4; i++){
        list.Add_node(new Node(i));
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