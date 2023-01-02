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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        vector<int> res;
        vector<int> ans;
        vector<int> var;
        ListNode* p;
        p = l1;
        
        while(p != NULL)
        {
            res.push_back(p->val);
            p = p->next;
        }
        
        reverse(res.begin(),res.end());
        
        p = l2;
        
        while(p != NULL)
        {
            ans.push_back(p->val);
            p = p->next;
        }
        
        reverse(ans.begin(),ans.end());
        
        int i,j,carry=0,x;
        
        i = res.size()-1;
        j = ans.size()-1;
        
        while(i >= 0 && j >= 0)
        {
            x = res[i] + ans[j] + carry;
            carry = x/10;
            x = x%10;
            var.push_back(x);
            i--;
            j--;
        }
        
        while(i >= 0)
        {
            x = res[i] + carry;
            carry = x/10;
            x = x%10;
            var.push_back(x);
            i--;
        }
        
        while(j >= 0)
        {
            x = ans[j] + carry;
            carry = x/10;
            x = x%10;
            var.push_back(x);
            j--;
        }
        
        if(carry == 1)
        {
           var.push_back(carry);    
        }
        
        // reverse(var.begin(),var.end());
        
        ListNode* temp = new ListNode();
        ListNode* q = temp;
        
        for(i=0;i<var.size();i++)
        {
            ListNode* curr = new ListNode(var[i]);
            q->next = curr;
            q = q->next;
        }
        
        return temp->next;
    }
};