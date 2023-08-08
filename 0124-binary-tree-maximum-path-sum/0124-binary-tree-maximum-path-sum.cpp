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
    
    int helper(TreeNode* root,int& ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int l = helper(root->left,ans);
        int r = helper(root->right,ans);
        
        int height = max({max(l,r) + root->val,root->val,0});
        
        ans = max({ans,l+r+root->val,l+root->val,r+root->val,root->val});
        
        return height;
    }
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        
        helper(root,ans);
    
        return ans;
    }
};