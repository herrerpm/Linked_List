# Linked_List

The following header is a model of a Linked List that I developed, it works by having a head and a sentinel node that points to null. By doing this the list can be iterated with ease. It uses class templates, which allow the list to be of any primitive data type defined by the user. More complicated structures would require especialization.

## Usage
---
- **Append:** The append function has only one parameter, which is the data type you want to store. The method then creates a node and creates a connection pointer between the last node and the new node, and then updates the last node to be the new node. The method also defines the first node appended as the head, after that the Is_head atribute is set to true, and all other nodes are treated normally.

  `list.Append(data: 7);`

- **PrintAll** The print all method iterates all over the list with a while loop. It follows the connections from the head's pointer until it arrives to the sentinel node that is pointing to a nullpointer, and it takes no argument.

  `list.Append(data: 6);`

- **Node_Address** The Node_Address method iterates over the list until it finds the desired node, it is important to note that the nodes are labeled as if they ranged from 1 to the list size, meaning that the Head node will always be one. The method returns a pointer to the node, and not the actual data.

  `list.Node_addres(node_number: 7);`

- **Modify** The modify method takes in data by the user and changes a desired node's data using the enumeration described above. 

  `list.Modify(node_number: 3);`

- **Remove** The remove method uses the number of a node to unlink it from the list. At the time the memory is not deleted, but it is a feature I will implement. The remove method has 3 cases, if the head node is removed it converts the second node into the head. If the last node is removed, it takes the node's prior next attribute and points it to a null pointer. The last case is if the node is in between, which will lead to the prior node changing it's connection towards the node after.

  `list.Remove(node_number: 5);`
  
## Updates
  ---
As of right now the list is fully functional for basic dynamic memory allocation, it works as a resizible array. Nonetheless, I plan to research on to how each node's data could be type independant.
  
