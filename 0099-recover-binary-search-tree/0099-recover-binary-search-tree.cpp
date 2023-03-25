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
    
    int i = 0;
    
    void inorder(TreeNode* root,vector<int>& res)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left != NULL)
        {
            inorder(root->left,res);
        }
        
        res.push_back(root->val);
        
        if(root->right != NULL)
        {
            inorder(root->right,res);
        }
    }
    
    void helper(TreeNode* root,vector<int>& res)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left != NULL)
        {
            helper(root->left,res);    
        }
        
        root->val = res[i++];
        
        if(root->right != NULL)
        {
            helper(root->right,res);
        }
    }
    
    void recoverTree(TreeNode* root) {
        
        vector<int>res;
        
        inorder(root,res);
        
        sort(res.begin(),res.end());
        
        helper(root,res);
        
        
    }
};