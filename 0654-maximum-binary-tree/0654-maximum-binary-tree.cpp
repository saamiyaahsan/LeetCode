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
      int get_index(int start,int end,vector<int>& nums)
    {
        int idx = 0,ans = INT_MIN;
        
        for(int i=start;i<=end;i++)
        {
            if(ans < nums[i])
            {
                ans = nums[i];
                idx = i;
            }
        }
        
        return idx;
    }
    
    TreeNode* helper(int start,int end,vector<int>& nums)
    {
        if(start > end)
        {
            return NULL;
        }
        
        int idx = get_index(start,end,nums);
        
        TreeNode* root = new TreeNode(nums[idx]);
        
        root->left = helper(start,idx-1,nums);
        root->right = helper(idx+1,end,nums);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return helper(0,nums.size()-1,nums);
    }
};