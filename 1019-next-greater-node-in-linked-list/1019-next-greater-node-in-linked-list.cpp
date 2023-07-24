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
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int>ans;
        vector<int>res;
        
        ListNode* p = head;
        
        while(p != NULL)
        {
            res.push_back(p->val);
            p = p->next;
        }
        
        stack<int>st;
        
        for(int i=res.size()-1;i>=0;i--)
        {
            if(st.empty() == true || i == res.size()-1)
            {
                ans.push_back(0);
                st.push(res[i]);
            }
            
            else
            {
                if(st.empty() == true)
                {
                    ans.push_back(0);
                    st.push(res[i]);
                }
                
                else
                {
                    while(st.empty() != true && st.top() <= res[i])
                    {
                        st.pop();
                    }
                    
                    if(st.empty() != true)
                    {
                        ans.push_back(st.top());
                    }
                    
                    else
                    {
                        ans.push_back(0);
                    }
                    
                    st.push(res[i]);
                }
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};