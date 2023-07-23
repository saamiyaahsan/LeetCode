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
        
        ListNode* p = l1;
        ListNode* q = l2;
        
        ListNode* Res = new ListNode(-1);
        ListNode* t = Res;
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
            int nodeSum = (p->val + carry)% 10;
            carry = (p->val+carry)/10;
            ListNode* newNode = new ListNode(nodeSum);
            t->next = newNode;
            t = t->next;
            p = p->next;
        }
        
         while(q != NULL)
        {
            int nodeSum = (q->val + carry)% 10;
            carry = (q->val+carry)/10;
            ListNode* newNode = new ListNode(nodeSum);
            t->next = newNode;
            t = t->next;
            q = q->next;
        }
        
        if(carry == 1)
        {
            int nodeSum = (carry) % 10;
            carry = carry/10;
            ListNode* newNode = new ListNode(nodeSum);
            t->next = newNode;
            t = t->next;
        }
        
        return Res->next;
    }
};