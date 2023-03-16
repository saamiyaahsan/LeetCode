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
    
    int idx;
    
    int position(int start,int end,vector<int>& inorder,int curr)
    {
        int k;
        
        for(int i=start;i<=end;i++)
        {
            if(inorder[i] == curr)
            {
                k = i;
            }
        }
        
        return k;
    }
    
    TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int start,int end)
    {
        if(start > end)
        {
            return NULL;
        }
        
        int curr = postorder[idx];
        
        TreeNode* root = new TreeNode(postorder[idx--]);
        
        int pos = position(start,end,inorder,curr);
        
        root->right = helper(inorder,postorder,pos+1,end);
        root->left = helper(inorder,postorder,start,pos-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        idx = inorder.size()-1;
        
        return helper(inorder,postorder,0,inorder.size()-1);
        
    }
};