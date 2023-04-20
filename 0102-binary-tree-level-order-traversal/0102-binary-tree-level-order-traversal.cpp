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
    vector<vector<int>> levelOrder(TreeNode* root) {
         
         vector<vector<int>>ans;
        
        
        if(root == NULL)
        {
            return ans;    
        }
        
       
        vector<int>res;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto x = q.front();
                q.pop();
                
                res.push_back(x->val);
                
                if(x->left != NULL)
                {
                    q.push(x->left);
                }
                
                if(x->right != NULL)
                {
                    q.push(x->right);
                }
            }
            
            ans.push_back(res);
            res.clear();
        }
        
        return ans;
    }
};