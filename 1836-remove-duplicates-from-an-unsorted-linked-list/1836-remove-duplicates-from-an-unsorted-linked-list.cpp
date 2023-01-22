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
        
        while(p != NULL)
        {
            mp[p->val]++;
            p = p->next;
        }
        
        ListNode* ans = new ListNode(-1);
        
        ListNode* prev = ans;
        
        p = head;
        
        while(p != NULL)
        {
            if(mp[p->val] > 1)
            {
                p = p->next;
            }
            
            else
            {
                prev->next = p;
                prev = prev->next;
                p = p->next;
            }
        }
        
        prev->next = p;
        
        return ans->next;
    }
};