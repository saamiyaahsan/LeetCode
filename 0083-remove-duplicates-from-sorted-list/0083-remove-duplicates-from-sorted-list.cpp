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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* p = head;
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        map<int,int>mp;
        
        while(p != NULL)
        {
            mp[p->val]++;
            
            p = p->next;
        }
        
        ListNode* x = new ListNode(-1);
        
        p = x;
        
        for(auto it : mp)
        {
              ListNode* curr = new ListNode(it.first);
              p->next = curr;
              p = p->next;
        }
        
        return x->next;
    }
};