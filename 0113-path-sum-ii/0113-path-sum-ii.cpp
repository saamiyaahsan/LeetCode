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
    
    void dfs(TreeNode* root,vector<int> res,vector<vector<int>>& ans,int targetSum)
    {
        if(root == NULL)
        {
            return;
        }
        
        res.push_back(root->val);
              
        if(root->left == NULL && root->right == NULL)
        {   
            if(targetSum - root->val == 0)
            {
                ans.push_back(res);
                return;
            }   
        }
            
        dfs(root->left,res,ans,targetSum-root->val);
        dfs(root->right,res,ans,targetSum-root->val);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>res;
        
        dfs(root,res,ans,targetSum);
        
        return ans;
    }
};