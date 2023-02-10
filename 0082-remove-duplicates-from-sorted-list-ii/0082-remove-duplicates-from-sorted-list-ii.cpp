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
   
          if(head == NULL || head->next == NULL)
          {
             return head;      
          }
        
          map<int,int>mp;        
          
           ListNode* p = head;
           
           ListNode* q = p;
           
           while(p != NULL)
           {
               mp[p->val]++;
               p = p->next;
           }
        
           ListNode* curr = new ListNode(-1); 
           p = curr;
           
           for(auto it : mp)
           {
               if(it.second == 1)
               {
                   ListNode* t = new ListNode(it.first);
                   p->next = t;
                   p = p->next;      
               }
             
           }
        
        return curr->next;
    }
};