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
        
        ListNode* newHead1 = NULL;
        ListNode* newHead2 = NULL;
        
        ListNode* p = l1;
        ListNode* q = l2;
        
        while(p != NULL)
        {
            ListNode* temp = p->next;
            p->next = newHead1;
            newHead1 = p;
            p = temp;
        }
        
        while(q != NULL)
        {
            ListNode* temp = q->next;
            q->next = newHead2;
            newHead2 = q;
            q = temp;
        }
        
        ListNode* res = new ListNode(-1);
        ListNode* t = res;
        
        p = newHead1;
        q = newHead2;
        
        int carry = 0;
        
        while(p != NULL && q != NULL)
        {
            int nodeSum = (p->val+q->val+carry)%10;
            carry = (p->val+q->val+carry)/10;
            ListNode* newNode = new ListNode(nodeSum);
            t->next = newNode;
            t = t->next;
            p = p->next;
            q = q->next;
        }
        
        while(p != NULL)
        {
            int nodeSum = (p->val+carry)%10;
            carry = (p->val+carry)/10;
            ListNode* newNode = new ListNode(nodeSum);
            t->next = newNode;
            t = t->next;
            p = p->next;
        }
        
        while(q != NULL)
        {
            int nodeSum = (q->val+carry)%10;
            carry = (q->val+carry)/10;
            ListNode* newNode = new ListNode(nodeSum);
            t->next = newNode;
            t = t->next;
            q = q->next;
        }
        
        if(carry != 0)
        {
            int nodeSum = (carry)%10;
            carry = (carry)/10;
            ListNode* newNode = new ListNode(nodeSum);
            t->next = newNode;
            t = t->next;
        }
        
        p = res->next;
        
        vector<int>ans;
        
        while(p != NULL)
        {
            ans.push_back(p->val);
            p = p->next;
        }
        
        reverse(ans.begin(),ans.end());
        
        p = res->next;
        
        int i = 0;
        
        while(p != NULL)
        {
            p->val = ans[i];
            i++;
            p = p->next;
        }
        
        return res->next;
    }
};


