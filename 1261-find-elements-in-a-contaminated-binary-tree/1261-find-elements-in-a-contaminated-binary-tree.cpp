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
class FindElements {
public:
    
    unordered_map<int,int>mp;
     queue<TreeNode*>q;     
    FindElements(TreeNode* root) {
    root->val = 0;         
    q.push(root);
        
    while(q.empty() != true)    
    {
       int n = q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* x = q.front();
            mp[x->val] = 1;
            q.pop(); 
       
         if(x->left != NULL)
        {
           x->left->val = 2*(x->val) + 1; 
           q.push(x->left);
        }
        
        if(x->right != NULL)
        {
            x->right->val = 2*(x->val) + 2;
            q.push(x->right);
        }
            
        }
      
    }  
    }
    
    bool find(int target) {
        
        if(mp[target] > 0 )
        {
            return true;
        }
        
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */