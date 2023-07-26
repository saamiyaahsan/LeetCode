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
    
   ListNode* mergeTwolists(ListNode* l1,ListNode* l2){
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode* first = new ListNode(1);
        ListNode* temp = first;
        while(l1 and l2){
           if(l1->val < l2->val){
               first->next = l1;
               l1 = l1->next;
           }else{
               first->next = l2;
               l2 = l2->next;
           }
           first = first->next;
        }
        while(l1){
         first->next = l1;
         first = first->next;
         l1 = l1->next;
        }
        while(l2){
           first->next = l2;
            first = first->next;
           l2 = l2->next;
        }
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       
        if(lists.size() == 1)return lists[0];
        if(lists.size() == 0)return nullptr;
        
        ListNode* ans = mergeTwolists(lists[1],lists[0]);
        for(int i = 2;i<lists.size();i++){
           
            ans = mergeTwolists(lists[i],ans);
        }
        return ans;
    }
};