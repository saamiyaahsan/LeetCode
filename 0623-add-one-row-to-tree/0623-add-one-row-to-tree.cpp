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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1)
        {
            TreeNode* curr = new TreeNode(val);
            curr->left = root;
            root = curr;
            return root;
        }
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        int curr_level = 0;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            curr_level++;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr_level == depth-1)
                {
                    TreeNode* res = new TreeNode(val);
                    res->left = curr->left;
                    curr->left = res;
                    
                    TreeNode* ans = new TreeNode(val);
                    ans->right = curr->right;
                    curr->right = ans;
                }
                
                else
                {
                    if(curr->left != NULL)
                    {
                        q.push(curr->left);
                    }
                    
                    if(curr->right != NULL)
                    {
                        q.push(curr->right);
                    }
                }
            }
        }
        
        return root;
    }
};