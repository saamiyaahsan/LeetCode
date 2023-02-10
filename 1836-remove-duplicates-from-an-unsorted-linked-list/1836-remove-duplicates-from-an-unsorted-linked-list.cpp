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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        
        unordered_map<int,int>mp;
        
        ListNode* p = head;
        
        ListNode* q = p;
        
        while(p != NULL)
        {
            mp[p->val]++;
            p = p->next;
        }
        
        ListNode* curr = new ListNode(-1);
        p = curr;
        
        q = head;
        
        while(q != NULL)
        {
            if(mp[q->val] > 1)
            {
                q = q->next;
            }
            
            else
            {
                ListNode* res = new ListNode(q->val);
                p->next = res;
                p = p->next;
                q = q->next;
            }
        }
        
        return curr->next;
    }
};