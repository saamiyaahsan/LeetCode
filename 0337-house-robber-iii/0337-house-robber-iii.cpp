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
    
    int helper(TreeNode* root,unordered_map<TreeNode*,int>& mp)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        if(mp.find(root) != mp.end())
        {
            return mp[root];
        }
        
        int ans_including_root = root->val;
        
        if(root->left != NULL)
        {
            ans_including_root = ans_including_root + helper(root->left->left,mp) + helper(root->left->right,mp);
        }
        
        if(root->right != NULL)
        {
             ans_including_root = ans_including_root + helper(root->right->left,mp) + helper(root->right->right,mp);
        }
        
        int ans_excluding_root = helper(root->left,mp) + helper(root->right,mp);
        
        int ans;
        
        ans = max(ans_including_root,ans_excluding_root);
        
        mp[root] = ans;
        
        return ans;
    }
    
    int rob(TreeNode* root) {
        
        unordered_map<TreeNode*,int>mp;
        
        return helper(root,mp);
    }
};