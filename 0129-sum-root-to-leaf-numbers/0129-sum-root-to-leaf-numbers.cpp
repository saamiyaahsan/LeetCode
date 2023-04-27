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
    
    void dfs(TreeNode* root,int t,int &ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        t = t*10 + root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            ans = ans + t;
            return;
        }
        
        dfs(root->left,t,ans);
        dfs(root->right,t,ans);
    }
    int sumNumbers(TreeNode* root) {
        
        int ans = 0,t = 0;
        
        dfs(root,t,ans);
        
        return ans;
    }
};