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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        
        
        vector<vector<int>>res;
        
        if(root == NULL)
        {
            return res;
        }
        
        map<int,vector<int>>mp;
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
        
        while(q.empty() != true)
        {
           int n = q.size();
            
           for(int i=0;i<n;i++)
           {
               TreeNode* t = q.front().first;
               int col = q.front().second;
               q.pop();
               mp[col].push_back(t->val);
               
               if(t->left != NULL)
               {
                   q.push({t->left,col-1});
               }
               
               if(t->right != NULL)
               {
                   q.push({t->right,col+1});
               }
           }
        }
        
        for(auto it : mp)
        {
            res.push_back(it.second);
        }
        
        return res;
    }
};