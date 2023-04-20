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
    
    void child_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
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
    int amountOfTime(TreeNode* root, int start) {
        
       unordered_map<TreeNode*,TreeNode*>parent;
       unordered_map<TreeNode*,bool>visited(false); 
       child_parent(root,parent); 
       
       queue<pair<TreeNode*,int>>Q; 
        
       queue<TreeNode*>q; 
       q.push(root); 
        
        
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
               Q.pop();
               
               TreeNode* t = x.first;
               int dis = x.second;
               ans = max(ans,dis);
               
               if(t->left != NULL && visited[t->left] == false)
               {
                   Q.push({t->left,dis+1});
                   visited[t->left] = true;
               }
               
               if(t->right != NULL && visited[t->right] == false)
               {
                   Q.push({t->right,dis+1});
                   visited[t->right] = true;
               }
               
               if(parent[t] != NULL && visited[parent[t]] == false)
               {
                   Q.push({parent[t],dis+1});
                   visited[parent[t]] = true;
               }
           }
       }
        
        return ans;
    }
};