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
    bool isCompleteTree(TreeNode* root) {
        
        int x = 1;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        int y = 1;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t == NULL)
                {
                    y = 0;
                }
                
                else
                {
                    if(y != 1)
                    {
                        return false;
                    }
                    
                   q.push(t->left);
                   q.push(t->right);
                }
            }
        }
        
        
        return true;
    }
};