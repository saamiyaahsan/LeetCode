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
    
    void helper(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        if(root == NULL)
        {
            return;
        }
        
        parent[root] = NULL;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(q.empty() != true)
        {
            auto t = q.front();
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        
        helper(root,parent);
        
        queue<TreeNode*>q;
        
        unordered_map<TreeNode*,bool>visited;
        
        queue<TreeNode*>Q;
        
        q.push(root);
        
        while(q.empty() != true)
        {
            auto it = q.front();
            q.pop();
            
            if(it->val == target->val)
            {
                Q.push(it);
                visited[it] = true;
                break;
            }
            
            if(it->left != NULL)
            {
                q.push(it->left);
            }
            
            if(it->right != NULL)
            {
                q.push(it->right);
            }
        }
        
        int curr_level = 0;
        
        while(Q.empty() != true)
        {
            int n = Q.size();
            
            if(curr_level == k)
            {
                break;
            }
            for(int i=0;i<n;i++)
            {
                auto t = Q.front();
                Q.pop();
                
                
                if(t->left != NULL && visited[t->left] == false)
                {
                    visited[t->left] = true;
                    Q.push(t->left);
                }
                
                if(t->right != NULL && visited[t->right] == false)
                {
                    visited[t->right] = true;
                    Q.push(t->right);
                }
                
                if(parent[t] != NULL && visited[parent[t]] == false)
                {
                    visited[parent[t]] = true;
                    Q.push(parent[t]);
                }
            }
            
            curr_level++;
        }
        
        vector<int>res;
        
        while(Q.empty() != true)
        {
            auto x = Q.front();
            Q.pop();
            
            res.push_back(x->val);
        }
        
        return res;
    }
};