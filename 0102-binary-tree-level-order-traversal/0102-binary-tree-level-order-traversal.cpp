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
       
        queue<TreeNode*>q;
        
        vector<vector<int>>res;
        
        if(root == NULL)
        {
            return res;
        }
        
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            vector<int>ans;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                ans.push_back(t->val);
                
                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
            }
            
            res.push_back(ans);
            ans.clear();
        }
        
        return res;
        
    }
};