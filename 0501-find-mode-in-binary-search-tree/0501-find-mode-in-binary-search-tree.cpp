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
    
    void helper(TreeNode* root,unordered_map<int,int>& mp)
    {
        if(root == NULL)
        {
            return;
        }
        
        mp[root->val]++;
        
        if(root->left != NULL)
        {
            helper(root->left,mp);
        }
        
        if(root->right != NULL)
        {
            helper(root->right,mp);
        }
    }
    
    vector<int> findMode(TreeNode* root) {
        
        unordered_map<int,int>mp;
        
        vector<int>res;
        
        helper(root,mp);
        
        int ans = INT_MIN;
        
        for(auto it : mp)
        {
            ans = max(ans,it.second);
        }
        
        for(auto it : mp)
        {
            if(it.second == ans)
            {
                res.push_back(it.first); 
            }
        }
        
        return res;
    }
};