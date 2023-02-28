/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int helper(TreeNode* root,map<int,int>& mp)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int p = helper(root->left,mp);
        int q = helper(root->right,mp);
        
        int r = root->val + p + q;
        
        mp[r]++;
        
        return r;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        map<int,int>mp;
        
        helper(root,mp);
        
        set<int>st;
        
        int ans = 0;
        
        for(auto it : mp)
        {
            ans = max(ans,it.second);
            st.insert(it.second);
        }
        
        vector<int>res;
        
        if(st.size() == 1)
        {
            for(auto it : mp)
        {
            res.push_back(it.first);
        }
            
        }
        
        else
        {
            for(auto it : mp)
            {
                if(ans == it.second)
                {
                    res.push_back(it.first);
                }
            }
        }
        
        return res;
    }
};