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
    
    int idx = 0;
    
    int position(int start,int end,vector<int>& preorder,vector<int>& inorder,int curr)
    {
        int k = -1;
        
        for(int i=start;i<=end;i++)
        {
            if(inorder[i] == curr)
            {
                k = i;
                break;
            }
        }
        
        return k;
    }
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int start,int end)
    {
        if(start > end)
        {
            return NULL;
        }
        
         int curr = preorder[idx];
    
        TreeNode* root = new TreeNode(preorder[idx++]);
        
        int pos = position(start,end,preorder,inorder,curr);
        
        root->left = helper(preorder,inorder,start,pos-1);
        root->right = helper(preorder,inorder,pos+1,end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return helper(preorder,inorder,0,preorder.size()-1);
        
    }
};