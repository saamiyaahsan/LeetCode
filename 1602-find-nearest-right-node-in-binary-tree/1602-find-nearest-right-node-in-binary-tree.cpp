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
    
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t->val == u->val)
                {
                    if(i == n-1)
                    {
                        return NULL;
                    }
                    
                    return q.front();
                }
                
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
        
        return NULL;
    }
};