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
    TreeNode* correctBinaryTree(TreeNode* root) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        parent[root] = NULL;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->right != NULL && parent.find(t->right) != parent.end())
                {
                   TreeNode* x = parent[t];
                   if(x->left == t)
                   {
                       x->left = NULL;
                   }
                    
                   else if(x->right == t)
                   {
                       x->right = NULL;
                   }
                    
                    return root;
                }
                
                if(t->left != NULL)
                {
                    parent[t->left] = t;
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    parent[t->right] = t;
                    q.push(t->right);
                }
            }
        }
        
        return root;
    }
};