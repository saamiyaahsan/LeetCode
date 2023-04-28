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
    
    void inorder(TreeNode* root,vector<int>& res)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left != NULL)
        {
            inorder(root->left,res);
        }
        
        res.push_back(root->val);
        
        if(root->right != NULL)
        {
            inorder(root->right,res);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        
        if(root == NULL)
        {
           return root;    
        }
        
        vector<int>res;
        inorder(root,res);
        
        unordered_map<int,int>mp;
        
        int sum = 0;
        
        for(int i=0;i<res.size();i++)
        {
            sum = sum + res[i];
        }
        
        for(int i=0;i<res.size();i++)
        {
            mp[res[i]] = sum;
            sum = sum - res[i];
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                t->val = mp[t->val];
                
                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
            }
        }
        
        return root;
    }
};