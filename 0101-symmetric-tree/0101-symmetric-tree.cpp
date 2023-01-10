class Solution {
public:
    
    bool Mirror(TreeNode* left,TreeNode* right)
    {
       if(left == NULL || right == NULL)
       {
           return right == left;
       }
        
       if(left->val != right->val)
       {
           return false;
       }
        
        return Mirror(left->left,right->right) && Mirror(left->right,right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
        {
            return true;
        }
        
        return Mirror(root->left,root->right);
    }
};