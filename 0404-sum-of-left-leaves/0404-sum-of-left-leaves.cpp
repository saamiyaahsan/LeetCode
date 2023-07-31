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
    
    bool isLeaf(TreeNode* x)
    {
        if(x->left == NULL && x->right == NULL)
        {
            return true;
        }
        
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        int ans = 0;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto x = q.front();
                q.pop();
                
                if(x->left != NULL)
                {
                    if(isLeaf(x->left) == true)
                    {
                        ans = ans + x->left->val;
                    }
                    
                    q.push(x->left);
                }
                
                if(x->right != NULL)
                {
                    q.push(x->right);
                }
            }
        }
        
        return ans;
    }
};