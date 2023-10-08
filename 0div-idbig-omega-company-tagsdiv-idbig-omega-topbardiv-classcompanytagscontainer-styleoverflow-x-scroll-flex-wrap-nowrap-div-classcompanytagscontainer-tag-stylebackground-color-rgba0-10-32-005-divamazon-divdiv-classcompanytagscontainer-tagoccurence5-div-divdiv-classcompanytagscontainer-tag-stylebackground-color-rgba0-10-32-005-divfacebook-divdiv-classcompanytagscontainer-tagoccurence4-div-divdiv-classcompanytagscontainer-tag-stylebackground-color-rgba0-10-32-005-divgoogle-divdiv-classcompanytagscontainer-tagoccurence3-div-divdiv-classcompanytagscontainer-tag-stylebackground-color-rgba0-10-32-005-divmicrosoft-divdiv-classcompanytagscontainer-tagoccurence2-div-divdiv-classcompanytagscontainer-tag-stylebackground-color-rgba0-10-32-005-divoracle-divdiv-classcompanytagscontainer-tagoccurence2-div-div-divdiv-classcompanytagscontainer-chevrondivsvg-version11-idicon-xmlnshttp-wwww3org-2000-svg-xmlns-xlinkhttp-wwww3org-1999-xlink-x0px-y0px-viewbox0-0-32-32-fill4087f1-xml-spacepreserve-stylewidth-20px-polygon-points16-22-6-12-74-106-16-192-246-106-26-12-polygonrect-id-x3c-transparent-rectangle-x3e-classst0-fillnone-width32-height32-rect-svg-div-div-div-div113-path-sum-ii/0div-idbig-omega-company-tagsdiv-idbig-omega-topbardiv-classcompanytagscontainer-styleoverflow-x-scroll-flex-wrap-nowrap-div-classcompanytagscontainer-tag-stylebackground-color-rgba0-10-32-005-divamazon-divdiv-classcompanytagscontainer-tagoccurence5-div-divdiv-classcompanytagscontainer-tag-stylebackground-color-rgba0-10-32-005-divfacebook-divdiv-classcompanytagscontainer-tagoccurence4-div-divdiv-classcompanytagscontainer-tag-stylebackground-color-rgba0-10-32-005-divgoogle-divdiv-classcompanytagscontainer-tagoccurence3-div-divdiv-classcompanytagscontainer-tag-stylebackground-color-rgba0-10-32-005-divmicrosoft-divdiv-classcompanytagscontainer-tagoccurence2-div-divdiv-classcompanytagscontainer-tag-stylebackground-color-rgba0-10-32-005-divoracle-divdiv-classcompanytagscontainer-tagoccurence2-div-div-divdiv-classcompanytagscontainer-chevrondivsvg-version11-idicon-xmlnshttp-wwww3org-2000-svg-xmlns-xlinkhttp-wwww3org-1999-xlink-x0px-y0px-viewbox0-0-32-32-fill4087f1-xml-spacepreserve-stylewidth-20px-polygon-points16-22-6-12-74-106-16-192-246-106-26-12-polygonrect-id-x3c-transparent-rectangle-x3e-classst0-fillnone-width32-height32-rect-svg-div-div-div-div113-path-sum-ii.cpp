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
    
    void PathSum2(TreeNode* root,int targetSum,vector<int>res,vector<vector<int>>& ans)
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
        
        PathSum2(root->left,targetSum-root->val,res,ans);
        PathSum2(root->right,targetSum-root->val,res,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int>res;
        
        vector<vector<int>>ans;
        
        PathSum2(root,targetSum,res,ans);
        
        return ans;
    }
};