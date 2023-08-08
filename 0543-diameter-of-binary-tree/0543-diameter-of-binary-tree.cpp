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
    
    int usingHeight(TreeNode* root,int& ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int l = usingHeight(root->left,ans);
        int r = usingHeight(root->right,ans);
        
        int h = max(l,r) + 1;
        
        ans = max(ans,l+r);
        
        return h;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
    
        int ans = 0;
        
        usingHeight(root,ans);
        
        return ans;
        
    }
};