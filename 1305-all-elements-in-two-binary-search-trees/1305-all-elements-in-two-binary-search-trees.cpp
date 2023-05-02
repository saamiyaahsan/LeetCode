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
    
    vector<int>res;
    
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        inorder(root1,res);
        inorder(root2,res);
        
        sort(res.begin(),res.end());
        
        return res;
    }
};