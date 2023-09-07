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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        vector<int>res;
        
        ListNode* p = head;
        
        while(p != NULL)
        {
            res.push_back(p->val);
            p = p->next;
        }
        
        int i,j;
        
        i = left - 1;
        j = right - 1;
        
        while(i < j)
        {
            swap(res[i],res[j]);
            i++;
            j--;
        }
        
        ListNode* t = new ListNode(-1);
        p = t;
        
        for(int i=0;i<res.size();i++)
        {
            ListNode* temp = new ListNode(res[i]);
            p->next = temp;
            p = p->next;
        }
        
        return t->next;
    }
};