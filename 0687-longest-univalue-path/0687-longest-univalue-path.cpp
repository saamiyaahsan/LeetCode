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
        
        if(root->left != NULL && root->left->val != root->val)
        {
            l = 0;
        }
        
        if(root->right != NULL && root->right->val != root->val)
        {
            r = 0;
        }
        
        int height = 1 + max(l,r);
        
        ans = max(ans,l+r);
        
        return height;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        int ans = 0;
        
        helper(root,ans);
        
        return ans;
    }
};