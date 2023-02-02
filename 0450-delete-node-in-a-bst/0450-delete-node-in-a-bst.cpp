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
    
    void inorder(TreeNode* root,vector<int>& res,int key)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left != NULL)
        {
            inorder(root->left,res,key);
        }
        
        if(root->val != key)
        {
            res.push_back(root->val);
        }
        
        if(root->right != NULL)
        {
            inorder(root->right,res,key);
        }
    }
    
    TreeNode* helper(TreeNode* root,int start,int end,vector<int>& res)
    {
        if(start > end)
        {
            return NULL;
        }
        
        int mid = (start + end)/2;
        
        TreeNode* curr = new TreeNode(res[mid]);
        
        curr->left = helper(root,start,mid-1,res);
        curr->right = helper(root,mid+1,end,res);
        
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        vector<int>res;
        
        inorder(root,res,key);
        
        int n = res.size()-1;
        
        return helper(root,0,n,res);
        
        
    }
};