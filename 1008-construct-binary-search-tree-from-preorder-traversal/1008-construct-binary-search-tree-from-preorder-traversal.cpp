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
    
    int position(int start,int end,vector<int>& preorder,vector<int>& inorder,int curr)
    {
        int k = -1;
        
        for(int i=start;i<=end;i++)
        {
            if(curr == inorder[i])
            {
               k = i;
               break; 
            }
        }
        
        return k;
    }
    TreeNode* BST(int start,int end,vector<int>& preorder,vector<int>& inorder)
    {
        if(start > end)
        {
            return NULL;
        }
        
        int curr = preorder[idx];
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        
        int pos = position(start,end,preorder,inorder,curr);
        
        root->left  = BST(start,pos-1,preorder,inorder);
        root->right = BST(pos+1,end,preorder,inorder);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        idx = 0;
        
        vector<int>inorder;
        
        for(auto it : preorder)
        {
            inorder.push_back(it);
        }
        
        sort(inorder.begin(),inorder.end());
        
        return BST(0,inorder.size()-1,preorder,inorder);
    }
};