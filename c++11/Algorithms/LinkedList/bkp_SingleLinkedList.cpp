
#include <assert.h>
#include <iostream>

#include <assert.h>

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
       head = nullptr;
       tail = nullptr;
       length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
       if (index > length-1) return -1;
        Node* ptr = getNode(index);
        if (nullptr != ptr) return ptr->val;
        return -1; 
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
      
     head = linkNewNode(getNewNodeWith(val), head);
			std::cout << "added at head : " << val << ", and length : " << length << std::endl;
      if (length == 1) tail = head;
      return;

    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
      tail = linkNewNode(tail, getNewNodeWith(val));

			std::cout << "added at tail : " << val << ", and length : " << length << std::endl;
      if (length == 1) head = tail;
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
       if (0 == index) return addAtHead(val);
       if (length == index) return addAtTail(val);
			 else if (index > length) return ;

       Node* itr = getNode(index-1);

			std::cout << "added at : " << itr->val << ", and length : " << length << std::endl;

       itr = linkNewNode(itr, getNewNodeWith(val));
       return ;
        
    }
    
    void printList()
    {
        Node* itr = head;
        while (itr != nullptr) { std::cout << "  " << itr->val << ", " ; itr = itr->next;}
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
      printList();  
        
      if (index >= length) return;
       
       if (0 == index)
       {
         head = unlinkNextNode(head);
         if (1 == length) tail = head;
       }
       else if (length-1 == index)
       {
         tail = getNode(length-1);
         unlinkNextNode(tail);
       }
       else
       {
          std::cout << "deleting at index : " << index ;
          unlinkNextNode(getNode(index-1));
       }

       return ;
        
    }
    
    private :
   
     class Node {
        public : 
        Node* next;
        int val;
    };
                         
    Node* getNode(int index)
    {
      Node* itr = head;
      while ((itr != nullptr) && (index > 0)) 
      {
          itr = itr->next;
          index--;
      }

      if (0 == index) return itr;
      return nullptr;
    }

    Node* linkNewNode(Node* posNode, Node* newNode)
    {
      if ((nullptr == posNode) && (posNode == newNode)) return nullptr;

      length++;

      if (nullptr == posNode) return newNode;
      if (nullptr == newNode) return posNode;

      if (posNode->next != nullptr)
      {
        newNode->next = posNode->next;
      }
      posNode->next = newNode;
      return posNode;
    }

  Node* unlinkNextNode(Node* posNode)
    {
      //std::cout << "deleting node of val : " << posNode->val;
      Node* delNode = posNode;
      if (nullptr != posNode->next) delNode = posNode->next;
      //std::cout << "deleting node of val of delNode : " << delNode->val;
      if (delNode != posNode)
      {
          std::cout << "delete element 1" << delNode->val << std::endl;
          posNode->next = delNode->next;
          delete delNode;
          delNode = nullptr;
      }
      else
      {
          std::cout << "delete element 2" << delNode->val << std::endl;
          delete delNode;
          delNode = nullptr;
          posNode = nullptr;
      }
      length--;
      return posNode;
    }


    Node* getNewNodeWith(int val)
    {
      Node* newNode = new(std::nothrow) Node;
      assert(nullptr != newNode);

      newNode->val = val;
      newNode->next = nullptr;  
      return newNode;
    }

    Node* head;
    Node* tail;
    int length;

};
/**
 ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
[[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
 */

1,2,7,0,

6,1,2,0,4,
4,
4,6,1,2,0,4
6,4,6,1,2,0,0,4

int main()
{
 MyLinkedList* obj = new MyLinkedList();
 std::cout << "obj->get(1) : " << obj->get(1) << std::endl;
 obj->addAtHead(1);
// obj->addAtTail(3);
 //obj->addAtIndex(1,2);
 std::cout << "obj->get(1) : " << obj->get(0) << std::endl;
 obj->deleteAtIndex(0);
 std::cout << "obj->get(1) : " << obj->get(1) << std::endl;

}

