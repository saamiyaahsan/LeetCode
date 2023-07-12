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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        
        ListNode* p = head;
        
        int cnt = 0;
        
        while(p != NULL)
        {
            cnt++;
            p = p->next;
        }
        
        if(cnt == n)
        {
            head = head->next;
            return head;
        }
          
        int NodetoBeDeleted = cnt - n;
        
        cnt = 0;
        
        p = head;
        
        while(cnt < NodetoBeDeleted-1)
        {
             p = p->next;
             cnt++;
        }
        
        ListNode* q = p;
        q = p->next;
        
        if(q->next != NULL)
        {
            p->next = q->next;
        }
        
        else
        {
            p->next = NULL;
        }
        
        return head;
    }
};