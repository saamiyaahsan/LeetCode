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
    
    void helper(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        if(root == NULL)
        {
            return;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        parent[root] = NULL;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->left != NULL)
                {
                    parent[t->left] = t;
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    parent[t->right] = t;
                    q.push(t->right);
                }
            }
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        
        helper(root,parent);
        
        queue<TreeNode*>q;
        q.push(root);
        
        int sum = 0;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if(parent[t] != NULL && parent[parent[t]] != NULL && parent[parent[t]]->val % 2 == 0)
                {
                    sum = sum + t->val;
                }
                
                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
            }
        }
        
        return sum;
    }
};