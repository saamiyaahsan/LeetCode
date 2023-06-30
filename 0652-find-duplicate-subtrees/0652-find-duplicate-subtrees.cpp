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
    
    string helper(TreeNode* root,unordered_map<string,int>& mp,vector<TreeNode*>& res)
    {
        if(root == NULL)
        {
            return "";
        }
        
        string t = "";
       
        t = t + to_string(root->val);
        t = t + "->";
        string left = helper(root->left,mp,res);
        t = t + left;
        t = t + "->";
        string right = helper(root->right,mp,res);    
        t = t + right;
        
        mp[t]++;
        
        if(mp[t] == 2)
        {
            res.push_back(root);
        }
        
        return t;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*>res;
        unordered_map<string,int>mp;
        
        helper(root,mp,res);
        
        return res;
    }
};