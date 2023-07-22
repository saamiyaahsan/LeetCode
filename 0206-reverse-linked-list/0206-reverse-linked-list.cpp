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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* newHead = NULL;
        
        ListNode* p = head;
        
        while(p != NULL)
        {
            ListNode* temp = p->next;
            p->next = newHead;
            newHead = p;
            p = temp;
        }
        
        return newHead;
    }
};