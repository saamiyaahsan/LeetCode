/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*>st;
        
        ListNode* p = head;
        
        while(p != NULL)
        {
            if(st.find(p) != st.end())
            {
                return p;
            }
            
            st.insert(p);
            p = p->next;
        }
        
        return NULL;
    }
};