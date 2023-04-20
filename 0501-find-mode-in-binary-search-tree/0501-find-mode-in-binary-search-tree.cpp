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
    
    void inorder(TreeNode* root,unordered_map<int,int>& mp)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left != NULL)
        {
            inorder(root->left,mp);
        }
        
        mp[root->val]++;
        
        if(root->right != NULL)
        {
            inorder(root->right,mp);
        }
    }
    
    vector<int> findMode(TreeNode* root) {
        
        unordered_map<int,int>mp;
        
        inorder(root,mp);
        
        int ans = INT_MIN;
        
        for(auto it : mp)
        {
            ans = max(ans,it.second);
        }
        
        vector<int>res;
        
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