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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* temp = new ListNode(-1);
        ListNode* res = temp;
        ListNode* p = list1;
        ListNode* q = list2;
        
        while(p != NULL && q != NULL)
        {
            if(p->val <= q->val)
            {
                res->next = p;
                p = p->next;
                res = res->next;
            }
            
            else
            {
                res->next = q;
                q = q->next;
                res = res->next;
            }
        }
        
        if(p != NULL)
        {
            res->next = p;
        }
        
        if(q != NULL)
        {
            res->next = q;
        }
        
        return temp->next;
    }
};