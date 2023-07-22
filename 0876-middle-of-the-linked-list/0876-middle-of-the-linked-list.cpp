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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* p = head;
        
        int cnt = 0;
        
        while(p != NULL)
        {
            cnt++;
            p = p->next;
        }
        
        if(cnt % 2 == 1)
        {
            p = head;
            
            int node = 0;
            
            while(node < (cnt)/2)
            {
                p = p->next;
                node++;
            }
            
            head = p;
        }
        
        else
        {
            p = head;
            
            int node = 0;
            
            while(node < (cnt/2))
            {
                p = p->next;
                node++;
            }
            
            head = p;
        }
        
        
        return head;
    }
};