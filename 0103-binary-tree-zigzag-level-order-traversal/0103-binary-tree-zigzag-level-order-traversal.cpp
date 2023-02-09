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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        
        int c = 0;
        
        vector<vector<int>>ans;
        
        if(root == NULL)
        {
            return ans;
        }
        
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            vector<int>level;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                level.push_back(t->val);
                
                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
            }
            
            if(c % 2 == 0)
            {
                ans.push_back(level);
                level.clear();
                c++;
            }
            
            else
            {
                reverse(level.begin(),level.end());
                ans.push_back(level);
                level.clear();
                c++;
            }
        }
        
        return ans;
    }
};