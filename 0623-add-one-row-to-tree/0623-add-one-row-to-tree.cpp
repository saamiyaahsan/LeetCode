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
    
    void child_parent(TreeNode* root,unordered_map<TreeNode*,int>& level)
    {
        if(root == NULL)
        {
            return;
        }
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        
        level[root] = 1;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto x = q.front();
                q.pop();
                
                TreeNode* t = x.first;
                int lvl = x.second;
                
                if(t->left != NULL)
                {
                    q.push({t->left,lvl+1});
                    level[t->left] = lvl + 1;
                }
                
                if(t->right != NULL)
                {
                    q.push({t->right,lvl+1});
                    level[t->right] = lvl + 1;
                }
            }
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        unordered_map<TreeNode*,int>level;
        
        child_parent(root,level);
        
        if(depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            newRoot->right = NULL;
            
            return newRoot;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(level[t] == depth-1)
                { 
                    if(t->left != NULL)
                    {
                        TreeNode* x = new TreeNode(val);
                        x->left = t->left;
                        t->left = x;
                    }
                    
                    else
                    {
                       TreeNode* x = new TreeNode(val);
                       t->left = x;
                       x->left = NULL; 
                    }
                    
                    if(t->right != NULL)
                    {
                        TreeNode* y = new TreeNode(val);
                        y->right = t->right;
                        t->right = y;
                    }
                    
                    else
                    {
                       TreeNode* y = new TreeNode(val);
                       t->right = y;
                       y->right = NULL; 
                    }
                }
                
                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
            }
        }
        
        return root;
    }
};