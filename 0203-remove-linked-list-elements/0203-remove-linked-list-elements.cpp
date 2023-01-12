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
        
        ListNode* p = head;
        
        ListNode* x = new ListNode(-1);
        
        ListNode* q = x;
        
        while(p != NULL)
        {
            if(p->val != val)
            {
                ListNode* curr = new ListNode(p->val);
                q->next = curr;
                q = q->next; 
            }
            
            p = p->next;
        }
        
        return x->next;
    }
};