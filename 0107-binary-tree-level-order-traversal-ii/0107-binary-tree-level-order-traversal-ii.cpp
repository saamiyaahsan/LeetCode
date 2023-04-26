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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>ans;
        
        if(root == NULL)
        {
           return ans;    
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            vector<int>res;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                res.push_back(t->val);
                
                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
            }
            
            ans.push_back(res);
            res.clear();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};