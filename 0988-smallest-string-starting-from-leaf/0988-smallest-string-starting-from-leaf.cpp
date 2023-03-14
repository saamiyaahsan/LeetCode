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
     
    void solve(string t,string &ans,TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        
        t = (char)(root->val + 'a') + t;
        
          solve(t,ans,root->left);
        solve(t,ans,root->right);
        
        if((ans == "" || t < ans ) && (root->left == NULL) && (root->right == NULL))
        {
            ans = t;
        }
         
    }
    string smallestFromLeaf(TreeNode* root) {
       
         string ans = "";
         string t = "";
         
         solve(t,ans,root);
         
        return ans;
    }
};