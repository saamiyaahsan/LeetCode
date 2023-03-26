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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        int i = 0;
        
        while(q.empty() != true && i < arr.size())
        {
            int n = q.size();
            
            for(int j=0;j<n;j++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->val != arr[i])
                {
                    continue;
                }
                
                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
                
                if(i == arr.size()-1 && t->left == NULL && t->right == NULL)
                {
                    return true;
                }
            }
            
            i++;
        }
        
        return false;
        
    }
};