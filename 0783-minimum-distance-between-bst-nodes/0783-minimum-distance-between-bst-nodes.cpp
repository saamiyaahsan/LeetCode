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
    
    vector<int> res;
    
    int i,j,p=INT_MAX;
    
    void inOrder(TreeNode* root)
    {
       if(root == NULL)
       {
           return;
       }
        
       inOrder(root->left);
        
       res.push_back(root->val);
        
       inOrder(root->right); 
    }
    
    int minDiffInBST(TreeNode* root) {
        
        inOrder(root);
        
        for(i=0;i<res.size();i++)
        {
            for(j=i+1;j<res.size();j++)
            {
                if(p > abs(res[i]-res[j]))
                {
                    p = abs(res[i]-res[j]);
                }
            }
        }
        
        return p;
    }
};