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
    
    int ans = 0;
    
    int totalNoOfNodes(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        return 1 + totalNoOfNodes(root->left) + totalNoOfNodes(root->right);
    }
    int helper(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int sum = root->val + helper(root->left) + helper(root->right);
        int cntofNodes = totalNoOfNodes(root);
        
        if(root->val == sum/cntofNodes)
        {
            ans++;
        }
        
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        
        helper(root);
        
        return ans;
    }
};