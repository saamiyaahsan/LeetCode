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
    
    void inorder(TreeNode* root,vector<int>& x)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left != NULL)
        {
            inorder(root->left,x);
        }
        
        x.push_back(root->val);
        
        if(root->right != NULL)
        {
            inorder(root->right,x);
        }
        
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
       vector<int>ans;
       vector<int>res; 
       
       inorder(root1,ans); 
       inorder(root2,res);
        
       int i,j;
       
        i = 0;
        
        j = res.size()-1;
        
       while(i < ans.size() && j >= 0)
       {
           if(ans[i] + res[j] == target)
           {
               return true;
           }
           
           else if(ans[i] + res[j] > target)
           {
               j--;
           }
           
           else
           {
               i++;
           }
       } 
        
        return false;
        
    }
};