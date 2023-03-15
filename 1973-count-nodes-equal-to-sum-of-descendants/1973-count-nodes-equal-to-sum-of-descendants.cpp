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
    
    long long helper(TreeNode* root,int& ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        long long left = helper(root->left,ans);
        long long right = helper(root->right,ans);
        
        if(root->val == left + right)
        {
            ans++;
        }
        
        return left+right+root->val;
    }
    int equalToDescendants(TreeNode* root) {
        
        int ans = 0;
        helper(root,ans);
        return ans;
    }
};