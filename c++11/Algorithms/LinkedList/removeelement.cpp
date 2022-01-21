/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* prev = nullptr;
        ListNode* itr = head;
        while (itr != nullptr)
        {
            if (itr->val == val) 
            {
                if (itr == head) 
                {
                    head = itr->next;
                    delete itr;
                    itr = head;
                }    
                else //if (prev != nullptr)
                {
                    prev->next = itr->next;
                    delete itr;
                    itr = prev->next;
                }         
            }
            else
            {
                prev = itr;
                itr = itr->next;
            }    
        }
        return head;
    }
};
