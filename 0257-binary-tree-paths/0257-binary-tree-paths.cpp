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
    
    void dfs(TreeNode* root,string t,vector<string>& res)
    {
        if(root == NULL)
        {
            return;
        }
        
        t = t + to_string(root->val);
        
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(t);
            return;
        }
        
        dfs(root->left,t+"->",res);
        dfs(root->right,t+"->",res); 
    
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>res;
        string t;
        
        dfs(root,t,res);
        
        return res;
    }
};