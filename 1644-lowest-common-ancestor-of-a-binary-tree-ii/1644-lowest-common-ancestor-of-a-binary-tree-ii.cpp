/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* root,vector<int>&res)
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
    
    
    TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root == NULL || root->val == p->val || root->val == q->val)
        {
            return root;
        }
        
        TreeNode* x = LCA(root->left,p,q);
        TreeNode* y = LCA(root->right,p,q);
        
        if(x != NULL && y != NULL)
        {
            return root;
        }
        
        else if(x != NULL)
        {
            return x;
        }
        
        return y;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<int>res;
        
        inorder(root,res);
        
        int c = 0;
        
        for(int i=0;i<res.size();i++)
        {
           if(res[i] == p->val)
           {
               c++;
           }
        }
        
        for(int i=0;i<res.size();i++)
        {
           if(res[i] == q->val)
           {
               c++;
           }
        }
        
        if(c < 2)
        {
            return NULL;
        }
        
        return LCA(root,p,q);
    }
};