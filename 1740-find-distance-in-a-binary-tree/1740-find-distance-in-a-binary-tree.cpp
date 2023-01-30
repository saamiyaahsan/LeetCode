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
    
    TreeNode* LCA(TreeNode* root,int p,int q)
    {
        if(root == NULL || root->val == p || root->val == q)
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
        
        else
        {
            return y;
        }
    }
    int findDistance(TreeNode* root, int p, int q) {
        
        TreeNode* lca = LCA(root,p,q); 
        
        queue<TreeNode*>Q;
        
        Q.push(lca);
        
        int a = -1,b = -1,level = 0;
        
        while(!Q.empty())
        {
            int n = Q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = Q.front();
                Q.pop();
                
                if(curr->val == p)
                {
                    a = level;
                }
                
                if(curr->val == q)
                {
                    b = level;
                }
                
               if(curr->left != NULL)
               {
                   Q.push(curr->left);
               }
                
                if(curr->right != NULL)
                {
                    Q.push(curr->right);
                }
            }
            
            level++;
        }
        
        return a+b;
    }
};