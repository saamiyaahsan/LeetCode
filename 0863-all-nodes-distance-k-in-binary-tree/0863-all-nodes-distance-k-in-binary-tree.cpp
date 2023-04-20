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
    
    void child_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        if(root == NULL)
        {
            return;
        }
        
        //parent[root] = NULL;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
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
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>res;
        
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,bool>visited(false);

        child_parent(root,parent);
        
        queue<TreeNode*>q;
        
        q.push(target);
        visited[target] = true;
        
        int curr_level = 0;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            if(curr_level++ == k)
            {
                break;
            }
            
            for(int i=0;i<n;i++)
            {
                auto t = q.front();
                q.pop();
              
                if(t->left != NULL &&  visited[t->left] == false)
                {
                    visited[t->left] = true;
                    q.push(t->left);
                }
                
                if(t->right != NULL && visited[t->right] == false)
                {
                    visited[t->right] = true;
                    q.push(t->right);
                }
                
                if(parent[t] != NULL && visited[parent[t]] == false)
                {
                    visited[parent[t]] = true;
                    q.push(parent[t]);
                }
            }
        }
        
        while(q.empty() != true)
        {
            auto p = q.front();
            q.pop();
            
            res.push_back(p->val);
        }
        
        return res;
    }
};