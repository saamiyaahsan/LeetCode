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
    
    void child_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent,unordered_map<TreeNode*,int>& lvl)
    {
        if(root == NULL)
        {
            return;
        }
        
        parent[root] = NULL;
        lvl[root] = 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto y = q.front();
                TreeNode* t = y.first;
                int level = y.second;
                q.pop();
                
                if(t->left != NULL)
                {
                    parent[t->left] = t;
                    lvl[t->left] = level + 1;
                    q.push({t->left,level+1});
                }
                
                if(t->right != NULL)
                {
                    parent[t->right] = t;
                    lvl[t->right] = level + 1;
                    q.push({t->right, level+1});
                }
            }
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,int>lvl;
        
        child_parent(root,parent,lvl);
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->val == x)
                {
                    int level = lvl[t];
                    TreeNode* x = parent[t];
                    
                    for(auto it : lvl)
                    {
                        if(it.second == level && parent[it.first] != x && it.first->val == y)
                        {
                            return true;
                        }
                    }
                }
                
                if(t->val == y)
                {
                    int level = lvl[t];
                    TreeNode* x = parent[t];
                    
                    for(auto it : lvl)
                    {
                        if(it.second == level && parent[it.first] != x && it.first->val == y)
                        {
                            return true;
                        }
                    }
                }
                
                if(t->left != NULL && t->right != NULL)
                {
                    if(t->left->val == x && t->right->val == y || t->left->val == y && t->right->val == x)
                    {
                        return false;
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
        
        return false;
    }
};