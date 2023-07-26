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
    
    priority_queue<int,vector<int>,greater<int>>pq;
    
    void helper(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        
        pq.push(root->val);
        
        if(root->left != NULL)
        {
            helper(root->left);
        }
        
        if(root->right != NULL)
        {
            helper(root->right);
        }
        
    }
    int kthSmallest(TreeNode* root, int k) {
       
        helper(root);
        int x = -1;
        while(pq.empty() != true && k != 0)
        {
            x = pq.top();
            pq.pop();
            k--;
        }
        
        return x;
    }
};