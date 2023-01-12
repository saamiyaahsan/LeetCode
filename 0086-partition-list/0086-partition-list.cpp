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
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        vector<int>ans;
        
        ListNode* p = head;
        
        while(p != NULL)
        {
            if(p->val < x)
            {
                ans.push_back(p->val);
            }
            
            p = p->next;
        }
        
        p = head;
        
        while(p != NULL)
        {
            if(p->val >= x)
            {
                ans.push_back(p->val);
            }
            
            p = p->next;
        }
        
//         p = head;
        
//         while(p != NULL)
//         {
//             if(p->val > x)
//             {
//                 ans.push_back(p->val);
//             }
            
//             p = p->next;
//         }
        
        p = head;
        
        for(int i=0;i<ans.size();i++)
        {
            p->val = ans[i];
            p = p->next;
        }
        
        return head;
    }
};