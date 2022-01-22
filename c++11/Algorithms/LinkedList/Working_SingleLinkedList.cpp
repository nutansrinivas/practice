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
       if (index >= length) return -1;
       Node* itr = head;
        while ((itr != nullptr) && (index > 0))
        {
            itr = itr->next;
            index--;
        }
        return itr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {      
        Node* temp = getNewNodeWith(val);
        temp->next = head;
        head = temp;
        length++;
        if (head->next == nullptr) tail = head;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
      Node* temp = getNewNodeWith(val);
      if (tail == nullptr) 
      {
          tail = temp;
          head = tail;
      }
      else
      {
        tail->next = temp;   
        tail = temp;
      }  
      length++;
      return ;  
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
       
       if (0 == index) return addAtHead(val);
       if (length == index) return addAtTail(val);
	   else if (index > length) return ;
      
       Node* itr = head;
       while ((itr != nullptr) && (index > 1))
       {
           itr = itr->next;
           index--;
       }    
       if (itr != nullptr)
       {    
        Node* temp = getNewNodeWith(val);
        temp->next = itr->next;
        itr->next = temp;
        length++;   
       }
       return ; 
    }
    
    void printList()
    {
        Node* itr = head;
        std::cout << "length : " << length << ": ";
        while (itr != nullptr) { std::cout << "  " << itr->val << ", " ; itr = itr->next;}
        std::cout << std::endl;
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
      if (index >= length) return;
       Node* itr = head;
       if (0 == index)
       {
         head = head->next;
         delete itr;
         itr = nullptr;
         length--;  
         if (head == nullptr) tail = nullptr;
         return ;  
       }
       
       while ((itr != nullptr) && (index > 1)) 
       {
           itr = itr->next;
           index--;
       }    
       
        if (itr != nullptr)
        {
            length--;
            Node* temp = itr->next;
            itr->next = temp->next;
            if (tail == temp) tail = itr;
            delete temp;
        }    
       // printList();  
       return ;
    }
    
    private :
   
     class Node {
        public : 
        Node* next;
        int val;
    };
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
