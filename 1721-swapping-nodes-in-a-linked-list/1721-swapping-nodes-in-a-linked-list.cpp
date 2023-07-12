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
    ListNode* swapNodes(ListNode* head, int k) {
        
        vector<int>nums;
        
        ListNode* p = head;
        
        while(p != NULL)
        {
            nums.push_back(p->val);
            p = p->next;
        }
        
        swap(nums[k-1],nums[nums.size()-k]);
        
        ListNode* temp = new ListNode(nums[0]);
        ListNode* q = temp;
        
        for(int i=1;i<nums.size();i++)
        {
            ListNode* res = new ListNode(nums[i]);
            q->next = res;
            q = res;
        }
        
        return temp;
    }
};