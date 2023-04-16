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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int>res;
        
        for(int i=0;i<lists.size();i++)
        {
           while(lists[i] != NULL)
           {
               res.push_back(lists[i]->val);
               lists[i] = lists[i]->next;
           }
        }
        
        sort(res.begin(),res.end());
        
        ListNode* t = new ListNode(-1);
        
        ListNode* p = t;
        
        for(int i=0;i<res.size();i++)
        {
            ListNode* curr = new ListNode(res[i]);
            p->next = curr;
            p = p->next;
        }
        
        return t->next;
    }
};