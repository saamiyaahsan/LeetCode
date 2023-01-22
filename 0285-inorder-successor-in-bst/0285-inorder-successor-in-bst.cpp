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
    
    vector<TreeNode*>res;
    
    void inorder(TreeNode* root,vector<TreeNode*>& res)
    {
       if(root == NULL)
       {
           return;
       }
        
       if(root->left != NULL)
       {
           inorder(root->left,res);
       }
        
       res.push_back(root); 
        
       if(root->right != NULL)
       {
           inorder(root->right,res);
       }
        
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
       
        inorder(root,res);
        
        int x = 0;
        
        for(int i=0;i<res.size();i++)
        {
            if(p->val == res[i]->val)
            {
                x = i;
                break;
            }
        }
        
        if(x == res.size()-1)
        {
            return NULL;
        }
        
        return res[x+1];
    }
};