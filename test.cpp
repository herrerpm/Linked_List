#include <iostream>
#include "LinkedList.h"

using std::cout;

int main(){
    auto list = Linked_list<int>();
    list.Append(7);
    list.Append(8);
    list.Append(9);
    list.Append(10);
    cout << "List data \n\n";
    list.PrintAll();
    cout << "\nRemove third node \n\n";
    list.Remove(3);
    list.PrintAll();
    cout << "\nModify second node \n\n";
    list.Modify(2, 2);
    list.PrintAll();
    cout << "\nPrint single node value \n\n";
    (*(list.Node_address(3))).Print();

}
