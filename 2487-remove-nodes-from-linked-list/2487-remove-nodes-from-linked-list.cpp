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
    ListNode* removeNodes(ListNode* head) {
        
        ListNode* p = head;
        
        vector<int>res;
        vector<int>ans;
        
        while(p != NULL)
        {
            res.push_back(p->val);
            p = p->next;
        }        
        
        reverse(res.begin(),res.end());
               
        ans.push_back(res[0]);
               
        int q = res[0];
               
        for(int i=1;i<res.size();i++)
        {      
            if(res[i] >= q)
            {
                ans.push_back(res[i]);
                q = res[i];
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        ListNode* curr = new ListNode(-1);
        p = curr;
        
        for(int i=0;i<ans.size();i++)
        {  
           ListNode* dep = new ListNode(ans[i]);
           p->next = dep;
           p = p->next; 
        }
        return curr->next;
    }
};