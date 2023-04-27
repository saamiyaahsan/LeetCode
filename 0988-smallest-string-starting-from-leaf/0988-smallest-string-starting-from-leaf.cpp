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
    
    void dfs(TreeNode* root,unordered_map<int,char>& mp,string t,vector<string>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        t = t + mp[root->val];
        
        if(root->left == NULL && root->right == NULL)
        {
            reverse(t.begin(),t.end());
            ans.push_back(t);
        }
        
        dfs(root->left,mp,t,ans);
        dfs(root->right,mp,t,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        
        unordered_map<int,char>mp;
        
        vector<string>ans;
        string t;
      
        for(int i=0;i<=25;i++)
        {
            mp[i] = 97+i;
        }
            
        dfs(root,mp,t,ans);
        
        sort(ans.begin(),ans.end());
        
        return ans[0];
    }
};