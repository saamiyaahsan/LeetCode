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
    
    string helper(TreeNode* root,vector<TreeNode*>& ans,map<string,int>& mp)
    {
        if(root == NULL)
        {
            return "#";
        }
        
        string p = helper(root->left,ans,mp);
        string q = helper(root->right,ans,mp);
        
        string t = to_string(root->val) + "#" + p + "#" + q;
        
        if(mp[t] == 1)
        {
            ans.push_back(root);
        }
        
       mp[t]++;
        
        
        return t;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        map<string,int>mp;
        vector<TreeNode*>ans;
        
        if(root == NULL)
        {
           return ans;    
        }
        
        helper(root,ans,mp);
        
        return ans;
    }
};