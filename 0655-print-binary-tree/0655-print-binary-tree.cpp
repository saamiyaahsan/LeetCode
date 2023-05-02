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
    
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        return 1 + max(height(root->left),height(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        
        int m = height(root);
        int n = pow(2,m) - 1;
        
        vector<vector<string>>ans(m,vector<string>(n));
        
        ans[0][(n-1)/2] = to_string(root->val);
        
        queue<pair<TreeNode*,pair<int,int>>>q;
        
        q.push({root,{0,(n-1)/2}});
        
        while(q.empty() != true)
        {
            auto x = q.front();
            q.pop();
            
            TreeNode* t = x.first;
            int row = x.second.first;
            int col = x.second.second;
            
            if(t->left != NULL)
            {
                int nrow = row + 1;
                int ncol = col - pow(2,m-2-row);
                
                ans[nrow][ncol] = to_string(t->left->val);
                
                q.push({t->left,{nrow,ncol}});
            }
            
            if(t->right != NULL)
            {
                int nrow = row + 1;
                int ncol = col + pow(2,m-2-row);
                
                ans[nrow][ncol] = to_string(t->right->val);
                
                q.push({t->right,{nrow,ncol}});
            }
        }
        return ans;
    }
};