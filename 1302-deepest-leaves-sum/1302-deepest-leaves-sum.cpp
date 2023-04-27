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
        
        level[root] = 0;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto y = q.front();
                q.pop();
                
                TreeNode* t = y.first;
                int lvl = y.second;
                
                if(t->left != NULL)
                {
                    level[t->left] = lvl + 1;
                    q.push({t->left,lvl+1});
                }
                
                if(t->right != NULL)
                {
                    level[t->right] = lvl + 1;
                    q.push({t->right,lvl+1});
                }
            }
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        
       unordered_map<TreeNode*,int>level;
        
       child_parent(root,level); 
       
       int Val;
        
       for(auto it : level)
       {
           Val = max(Val,it.second);
       }
       
       int ans = 0; 
        
       queue<TreeNode*>q; 
       q.push(root);
        
       while(q.empty() != true)
       {
           int n = q.size();
           
           for(int i=0;i<n;i++)
           {
               TreeNode* t = q.front();
               q.pop();
               
               if(level[t] == Val)
               {
                   ans = ans + t->val;
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
        
       return ans; 
        
    }
};