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
    
    int cnt = 0;
    
    void helper(TreeNode* root,long long targetSum)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(targetSum-root->val == 0)
        {
            cnt++;
            // return;
        }
        
        helper(root->left,targetSum-root->val);
        helper(root->right,targetSum-root->val);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root != NULL)
        {
            helper(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        
        
        return cnt;
    }
};