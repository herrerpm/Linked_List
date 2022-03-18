#include <iostream>
#include "LinkedList.h"

using std::cout;

int main(){
    auto list = Linked_list<std::string>();
    list.Append("s");
    list.Append("f");
    list.Append("8.3");
    list.Append("9");
    cout << "List data \n\n";
    list.PrintAll();
    cout << "\nRemove third node \n\n";
    list.Remove(3);
    list.PrintAll();
    cout << "\nModify second node \n\n";
    list.Modify(2, "dfd4");
    list.PrintAll();
    cout << "\nPrint single node value \n\n";
    list.Print_node(list.Node_address(3));

}