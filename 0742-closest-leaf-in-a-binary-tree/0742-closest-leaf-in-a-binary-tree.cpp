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
    
    void Child_Parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        if(root == NULL)
        {
            return;
        }
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        parent[root] = NULL;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* x = q.front();
                q.pop();
                
                if(x->left != NULL)
                {
                    parent[x->left] = x;
                    q.push(x->left);
                }
                
                if(x->right != NULL)
                {
                    parent[x->right] = x;
                    q.push(x->right);
                }
            }
        }
    }
    int findClosestLeaf(TreeNode* root, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        
        Child_Parent(root,parent);
        
        unordered_map<TreeNode*,bool>visited(false);
        
        queue<TreeNode*>q;
        q.push(root);
        
        queue<pair<TreeNode*,int>>Q;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* x = q.front();
                q.pop();
                
                if(x->val == k)
                {
                    Q.push({x,0});
                    visited[x] = true;
                    break;
                }
                
                if(x->left != NULL)
                {
                    q.push(x->left);
                }
                
                if(x->right != NULL)
                {
                    q.push(x->right);
                }
            }
        }
        
        int ans = INT_MAX,p=0;
        
        while(Q.empty() != true)
        {
            int n = Q.size();
            
            for(int i=0;i<n;i++)
            {
                auto y = Q.front();
                Q.pop();
                
                TreeNode* x = y.first;
                int dis = y.second;
                
                if(x->val != k)
                {
                    if(x->left == NULL && x->right == NULL && ans > dis)
                    {
                        p = x->val;
                        ans = dis;
                    }
                    
                    if(x->left != NULL && visited[x->left] == false)
                    {
                        Q.push({x->left,dis+1});
                        visited[x->left] = true;
                    }
                    
                    if(x->right != NULL && visited[x->right] == false)
                    {
                        Q.push({x->right,dis+1});
                        visited[x->right] = true;
                    }
                    
                    if(parent[x] != NULL && visited[parent[x]] == false)
                    {
                        Q.push({parent[x],dis+1});
                        visited[parent[x]] = true;
                        
                    }
                }
                
                else
                {
                    if(x->left == NULL && x->right == NULL)
                    {
                        return x->val;
                    }
                    
                    if(x->left != NULL && visited[x->left] == false)
                    {
                        Q.push({x->left,dis+1});
                        visited[x->left] = true;
                    }
                    
                    if(x->right != NULL && visited[x->right] == false)
                    {
                        Q.push({x->right,dis+1});
                        visited[x->right] = true;
                    }
                    
                    if(parent[x] != NULL && visited[parent[x]] == false)
                    {
                        Q.push({parent[x],dis+1});
                        visited[parent[x]] = true;
                        
                    }
                }
            }
        }
        
        return p;
    }
};