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
    
    void helper(TreeNode* root,map<TreeNode*,TreeNode*>& parent)
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
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->left != NULL)
                {
                    q.push(t->left);
                    parent[t->left] = t;
                }
                
                if(t->right != NULL)
                {
                    q.push(t->right);
                    parent[t->right] = t;
                }
            }
        }
        
    }
    int amountOfTime(TreeNode* root, int start) {
        
      map<TreeNode*,TreeNode*>parent;   
      map<TreeNode*,bool>visited;   
        helper(root,parent);
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        queue<pair<TreeNode*,int>>Q;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->val == start)
                {
                    Q.push({t,0});
                    visited[t] = true;
                    break;
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
        
        int ans = INT_MIN;
        
        while(Q.empty() != true)
        {
            int n = Q.size();
            
            for(int i=0;i<n;i++)
            {
                auto x = Q.front();
                
                TreeNode* y = x.first;
                int time = x.second;
                
                ans = max(ans,time);
                
                Q.pop();
                
                if(parent[y] != NULL && visited[parent[y]] == false)
                {
                    visited[parent[y]] = true;
                    Q.push({parent[y],time + 1});
                }
                
                if(y->left != NULL && visited[y->left] == false)
                {
                    visited[y->left] = true;
                    Q.push({y->left,time+1});
                }
                
                if(y->right != NULL && visited[y->right] == false)
                {
                    visited[y->right] = true;
                    Q.push({y->right,time+1});
                }
            }
        }
        
        
        return ans;
    }
};