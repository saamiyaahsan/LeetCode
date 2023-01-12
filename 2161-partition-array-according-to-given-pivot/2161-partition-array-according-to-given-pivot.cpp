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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* p;
        p = head;
        
        vector<int> res;
        vector<int> ans;
        
        if(head == NULL || head->next == NULL)
        {
          return head;    
        }
        
        while(p != NULL)
        {
            if(p->val < x)
            {
                res.push_back(p->val);
                p = p->next;
            }
            
            else
            {
                ans.push_back(p->val);
                p = p->next;
            }
        }
        
        int i;
        
        for(i=0;i<ans.size();i++)
        {
            res.push_back(ans[i]);
        }
        
        i = 0;
        p = head;
        
        while(p != NULL)
        {
            p->val = res[i];
            i++;
            p = p->next;
        }
        
        return head;
    }
};