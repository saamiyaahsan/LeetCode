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
    ListNode* plusOne(ListNode* head) {
     
     vector<int>arr;  
     vector<int>res;
        
     ListNode* p = head;   
     
     while(p != NULL)   
     {
        arr.push_back(p->val);
        p = p->next; 
     }   
      
     reverse(arr.begin(),arr.end());  
     
     int sum = 0,carry = 1,i=0;   
        
     while(i < arr.size())
     {
         sum = arr[i] + carry;
         res.push_back(sum % 10);
         carry = sum/10;
         i++;
     }
        
      if(carry == 1)  
      {
          res.push_back(carry);
      }
        
     ListNode* ans = new ListNode(-1);   
     
        p = ans;
        
     for(i=res.size()-1;i>=0;i--)
     {
         ListNode* curr = new ListNode(res[i]);
         p->next = curr;
         p = p->next;
     }
        
        return ans->next;
    }
};